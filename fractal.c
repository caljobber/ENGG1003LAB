#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int red(int h);
int green(int h);
int blue(int h);
int main(){
    double x0=-2.0, y0=1.0, xn= x0, yn=y0, xt;
    int i=0, maxi=1000;//iteration counter&max iterations
    int height=4000, width=8000, heightc=0, widthc=0;
    double incw=(double)(-2.0*x0)/(double)width;//increment for width
    double dech=(double)2*y0/(double)height; //decrement for height
    //height & width of image, c is counter for each pixel drawn
    FILE *output;//defining file pointer
    output = fopen("fractest.ppm", "w");
    fprintf(output, "P3\n%d %d\n255\n", width, height);
    for(heightc=0; heightc<height; heightc++){
        x0=-2.0;
        widthc=0;
        for(widthc=0; widthc<width; widthc++){
            xn=x0, yn=y0;//begin mandelbrot test sequence
            for(i=0; (i<maxi && xn*xn+yn*yn<=4); i++){
            xt=((xn*xn-yn*yn)+x0);
            yn=(2*xn*yn+y0);
            xn=xt;
            }
            int h=(360*i/maxi), R, G, B;
            R= red(h);
            G= green(h);
            B= blue(h);

            //attempt to print to body
            fprintf(output, "%d %d %d\n", R, G, B);
            x0+=incw;//width increment

            }

        y0-=dech;//height decrement

    }
    fclose(output);
    return 0;
}
int red(int h){

    int X =(1-(abs((h/60)%2-1)));
    int R;
    if((h>=0) && (h<60))
        R=255;
    else if((h>=60) && (h<120))
        R=X*255;
    else if((h>=120) && (h<240))
        R=0;
    else if((h>=240) && (h<300))
        R=X*255;
    else if((h>=300) && (h<360))
        R=255;
return R;
}


int green(int h){
    int X =(1-(abs((h/60)%2-1)));
    int G;
    if((h>=0) && (h<60))
        G=X*255;
    else if((h>=60) && (h<180))
        G=255;
    else if((h>=180) && (h<240))
        G=X*255;
    else if((h>=240) && (h<360))
        G=0;
return G;
}


int blue(int h){
    int X =(1-(abs((h/60)%2-1)));
    int B;
    if((h>=0) && (h<120))
        B=0;
    else if((h>=120) && (h<180))
        B=X*255;
    else if((h>=180) && (h<300))
        B=255;
    else if((h>=300) && (h<360))
        B=X*255;

return B;
}
