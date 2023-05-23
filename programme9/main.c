#include <stdio.h>

int main()
{
    const float pi=3.14;
    int l,b,r,area,perimeter_of_rectangle, circumference_of_circe;
    float Area_circle;
    printf("_____________________________rectangle_________________________\n");

    printf("enter the length and breadth and radius!\n");
    scanf("%d%d%d",&l,&b,&r);

    area=l*b;
    printf("%d\n",area);


      printf("_______________perimeter of rectangle________________\n");
    perimeter_of_rectangle=2*l+2*b;//4 6
      printf("%d",perimeter_of_rectangle);

       printf("_______________Area of circle________________\n");
      Area_circle=pi*r*r;//3.14
       printf("%f",Area_circle);

        printf("_______________circumference of circle________________\n");
       circumference_of_circe=pi*r*2;
        printf("%f",circumference_of_circe);





    return 0;
}
