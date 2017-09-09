//
//  main.cpp
//  Aula-Ordenacao
//
//  Created by Eiji Adachi Medeiros Barbosa on 09/03/17.
//  Copyright © 2017 Eiji Adachi Medeiros Barbosa. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>
#include "Sort.hpp"

using namespace std;

bool isOrdered(int[], int);

bool readInput(const string, int[], int);

int main(int argc, const char * argv[]) {
    if(argc != 3){
        cout << "Programa espera argumentos:\narg1 - indicando o caminho do arquivo de entrada\narg2 - indicando a quantidade de números a serem lidos da entrada" << endl;
        return -1;
    }
    
    const string path = argv[1];
    const int size = stoi(argv[2]);
    
    int* v = new int[size];
    bool read = readInput(path, v, size);
    if(!read)
    {
        return -1;
    }
    
    cout << "Dados lidos corretamente. Executando ordenação..." << endl;
    
    // inicio da medição
    auto start = std::chrono::high_resolution_clock::now();
    
    sort(v, size);
    
    // fim da medição
    auto end = std::chrono::high_resolution_clock::now();
    
    if( !isOrdered(v, size) )
    {
        cout << "Dados de entrada não estão ordenados corretamente" << endl;
        return -1;
    }
    
    // duração da medição
    auto dur = end - start;
    
    auto f_secs = std::chrono::duration_cast<std::chrono::duration<float>>(dur);
    
    cout << setprecision(4) << f_secs.count() << " s" << endl;
    
    return 0;
}

/*
 Checks if a given array is in ascending order.
 */
bool isOrdered(int v[], int size)
{
    for(int i = 1; i < size; i++)
    {
        if(v[i-1] > v[i])
        {
            return false;
        }
    }
    
    return true;
}

/*
 Reads file.
 */
bool readInput(const string path, int v[], int size){
    ifstream file(path);
    
    if(!file.is_open())
    {
        cout << "Não foi possível abrir o arquivo: " << path << endl;
        return false;
    }
    
    int max;
    file >> max;
    
    if( size > max )
    {
        cout << "O arquivo " << path << " contém apenas " << max << " elementos." << endl;
        return false;
    }
    
    for( int i = 0; i < size; i++){
        int x;
        file >> x;
        v[i] = x;
    }
    
    file.close();
    
    return true;
}
