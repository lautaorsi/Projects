#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>    //For read/write operations
#include <opencv2/imgproc.hpp>    //For processing
#include <opencv2/highgui.hpp>      //For showing image
#include <string.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
 
using namespace cv;
using namespace std;
 
int main()
{

    string fileName;
    cout << "Ingresa nombre de imagen a decodificar: \n";
    cin >> fileName;

    system("clear");
    
    //Leemos archivo
    Mat encodedMatrix = imread(fileName,IMREAD_GRAYSCALE);

    if ( encodedMatrix.empty()) {
        cout << "El archivo no existe (o no se desencriptarlo todavia)." << endl;
        return -1;
    }
    
    //Desencriptamos
    transpose(encodedMatrix,encodedMatrix); 

    //Obtenemos cant de filas y columnas
    int cols = encodedMatrix.cols;
    int rows = encodedMatrix.rows;

    string myText;

    //Recorremos matriz
    for(int i = 0; i < cols; i++){
        u_char character;
        for(int j = 0; j < rows; j++){
            
            //Obtenemos caracter
            character = *encodedMatrix.ptr<u_char>(i,j);

            //Si es salto de linea o EOF salimos de inner
            if(character == 33 || character == 255){
                break;    
            }

            //Caso contrario agregamos a renglon
            myText += character;
        }
        //Printeamos renglon y lo limpiamos
        printf("%s \n", myText.c_str());
        myText.clear();

        //Si era EOF termina programa
        if(character == 33){
            break;    
        }
    }

    return 0;
}