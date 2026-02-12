#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>    //For read/write operations
#include <opencv2/imgproc.hpp>    //For processing
#include <opencv2/highgui.hpp>      //For showing image
#include <fstream>
#include <iostream>
 
using namespace cv;
using namespace std;
 
int main()
{
    int w = 640;    

    Mat grayscale_image(w, w, CV_8UC1, Scalar(255));    //Hacemos que sea cuadrada y blanca

    
    string myText;
    
    ifstream MyReadFile("aText.txt");
    
    int i = 0;
    while (getline (MyReadFile, myText)) {
        int j = 0;
        while(myText[j] != '\0'){
            printf("%c", myText[j]);
            rectangle(grayscale_image, Point(j,i), Point(j,i), myText[j], FILLED);
            j++;
        }
        i++;
    }
    
    // Close the file
    MyReadFile.close();



    
    if ( grayscale_image.empty()) {
        cout << "Could not create image." << endl;
        return -1;
    }

    imshow("White Grayscale Image", grayscale_image);

    
    waitKey(0);

    imwrite("grayscale_image.png", grayscale_image);

    return 0;

}