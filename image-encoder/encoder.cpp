#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>    //For read/write operations
#include <opencv2/imgproc.hpp>    //For processing
#include <opencv2/highgui.hpp>      //For showing image
#include <unistd.h>
#include <fstream>
#include <iostream>
 
using namespace cv;
using namespace std;

int main()
{
    int w = 640;    

    Mat grayscale_image(w, w, CV_8UC1, Scalar(255));    //Hacemos que sea cuadrada y blanca

    string fileName;
    cout << "Ingresa nombre de archivo: \n";
    cin >> fileName;
    system("clear");
    cout << "Encriptando. \n";
    sleep(1);
    system("clear");
    cout << "Encriptando.. \n";
    sleep(1);
    system("clear");
    cout << "Encriptando... \n";
    sleep(2);
    system("clear");
    cout << "Archivo encriptado con éxito! \n";
    string myText;
    
    //Leemos archivo
    ifstream MyReadFile(fileName);
    
    //Por cada fila leemos las letras y asignamos su codigo ascii como escala gris en matriz de imagen
    int i = 0;
    int j = 0;
    while (getline (MyReadFile, myText)) {
        j = 0;
        while(myText[j] != '\0'){
            rectangle(grayscale_image, Point(j,i), Point(j,i), myText[j], FILLED);
            j++;
        }
        i++;
    }
    rectangle(grayscale_image, Point(j,i-1), Point(j,i-1), 33, FILLED);
    // Cerramos archivo
    MyReadFile.close();

    transpose(grayscale_image,grayscale_image);

    
    if ( grayscale_image.empty()) {
        cout << "Could not create image." << endl;
        return -1;
    }

    imwrite("encriptado.png", grayscale_image);

    return 0;

}