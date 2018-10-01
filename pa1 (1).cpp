//
//  pa1.cpp
//  ProgrammingAssignment#1 Magic Squares
//  Created by Dania Etienne  on 09/29/17.
//  Copyright © 2017 Dania Etienne . All rights reserved.
//

#include <iostream>
using namespace std;

// In this code an input(N) of a user between is used to produce 5 different N*N magic squares.

// A magic square is a N*N matrix of the integers 1 to N^2 where the sums of all the rows, columns, and diagonals are equal.Each number in the matrix occurs exactly once.


int main(int argc, const char * argv[]) {
    
    //STEP ONE: The user is asked to specify the size of the magic square. This value is assigned to N.
    // The boolean variable show is also created to end the program if an invalid number  is entered.
    bool show=false;
    int N=0;
    int Input=0;
    std::cout << "INPUT>> Enter the size of a magic square:";
    cin>>Input;
    std::cout <<"\n";
    
    // The if statement takes care of really large or small numbers that are not odd.
    if (Input>2 && Input<16){
        //checks if between 2 and 16.
        if (Input%2==0){
            // checks if odd.
        }
        else{
            N=Input;
            show=true;
        }
    }
    if (show==true){
        
        //STEP TWO: The magic square is created and the values are assigned to zero.
        int Magic[N][N];
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                Magic[i][j]=0;
            }
        }
        
        //STEP THREE: The first/original magic square is produced.
        
        int Lim= (N*N);
        int Initial = 1;
        int row = 0;
        int col = (N / 2);
        int row1;
        int col1;
        while (Initial <= Lim) {
            Magic[row][col] = Initial;
            Initial ++;
            row1 = row;
            col1 = col;
            row -= 1;
            col += 1;
            if (row == -1) {
                row = N - 1;
            }
            if (col == N) {
                col = 0;
            }
            if (Magic[row][col] != 0) {
                row = row1 + 1;
                col = col1;
                if (row == -1) {
                    row = N - 1;
                }
            }
        }
        
        // A for loop is used to prints out the Matrix.
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout <<(Magic[i][j]);
                std::cout <<" ";
            }
            std::cout <<"\n";
        }
        std::cout <<"\n";
        
        //Calculate the sums of every row:
        std::cout << "OUTPUT>> Checking the sums of every row:";
        int sumRow=0;
        for( int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (j==(N-1)){
                    sumRow+= Magic[i][j];
                    cout << sumRow;
                    cout << " ";
                    sumRow=0;
                }
                else{
                    sumRow+= Magic[i][j];
                }
            }
        }
        //Calculate the sums of every column:
        std::cout << "OUTPUT>> Checking the sums of every column:";
        int sumCol=0;
        for( int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (j==(N-1)){
                    sumCol+=Magic[j][i];
                    std::cout << sumCol;
                    std::cout << " ";
                    sumCol=0;
                }
                else{
                    sumCol+=Magic[j][i];
                }
            }
        }
        
        // Calculate sums of the diagonals:
        std::cout << "OUTPUT>> Checking the sums of every diagonal:";
        int diag1=0;
        int diag2=0;
        
        for (int i=0; i<N; i++) {
            int j=i;
            if (j==(N-1)) {
                (diag1)+=Magic[i][j];
                std::cout << diag1;
                std::cout << " ";
            }
            else {
                (diag1)+=Magic[i][j];
            }
        }
        
        for(int i=0; i<N;i++){
            int n=(N-i-1);
            if(i==(N-1)){
                (diag2)+=Magic[i][n];
                std::cout << diag2;
                std::cout << " ";
            }
            else{
                (diag2)+=Magic[i][n];
            }
        }
        std::cout <<"\n";
        std::cout <<"\n";
        
        //STEP FOUR: The second magic square is printed out.
        int MirrorFlip[N][N];
        
        int m=0;
        int n=0;
        for (int a=0; a<N ;a++) {
            for (int b=0; b<N ;b++){
                m=N-1-a;
                n=N-1-b;
                MirrorFlip[a][b]=Magic[m][n];
            }
        }
        // Prints out Matrix.
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++){
                std::cout <<(MirrorFlip[i][j]);
                std::cout <<" ";
            }
            std::cout <<"\n";
        }
        std::cout <<"\n";
        
        //Calculate the sums of every row:
        std::cout << "OUTPUT>> Checking the sums of every row:";
        sumRow=0;
        for( int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (j==(N-1)){
                    sumRow+= MirrorFlip[i][j];
                    cout << sumRow;
                    cout << " ";
                    sumRow=0;
                }
                else{
                    sumRow+= MirrorFlip[i][j];
                }
            }
        }
        //Calculate the sums of every column:
        std::cout << "OUTPUT>> Checking the sums of every column:";
        sumCol=0;
        for( int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (j==(N-1)){
                    sumCol+=MirrorFlip[j][i];
                    std::cout << sumCol;
                    std::cout << " ";
                    sumCol=0;
                }
                else{
                    sumCol+=MirrorFlip[j][i];
                }
            }
        }
        
        // Calculate sums of the diagonals:
        std::cout << "OUTPUT>> Checking the sums of every diagonal:";
        diag1=0;
        diag2=0;
        for (int i=0; i<N; i++) {
            int j=i;
            if (j==(N-1)) {
                (diag1)+=MirrorFlip[i][j];
                std::cout << (diag1);
                std::cout << " ";
            }
            else {
                (diag1)+=MirrorFlip[i][j];
            }
        }
        
        for(int i=0; i<N;i++){
            int n=(N-i-1);
            if(i==(N-1)){
                (diag2)+=MirrorFlip[i][n];
                std::cout << (diag2);
                std::cout << " ";
            }
            else{
                (diag2)+=MirrorFlip[i][n];
            }
        }
        std::cout <<"\n";
        std::cout <<"\n";
        
        
        //STEP FIVE: The third magic square is produced.
        int Rotate[N][N];
        
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++){
                Rotate[i][j]=Magic[N-j-1][i];
            }
        }
        // Prints out Matrix.
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++){
                std::cout <<(Rotate[i][j]);
                std::cout <<" ";
            }
            std::cout <<"\n";
        }
        std::cout <<"\n";
        
        //Calculate the sums of every row:
        std::cout << "OUTPUT>> Checking the sums of every row:";
        sumRow=0;
        for( int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (j==(N-1)){
                    sumRow+= Rotate[i][j];
                    cout << sumRow;
                    cout << " ";
                    sumRow=0;
                }
                else{
                    sumRow+= Rotate[i][j];
                }
            }
        }
        //Calculate the sums of every column:
        std::cout << "OUTPUT>> Checking the sums of every column:";
        sumCol=0;
        for( int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (j==(N-1)){
                    sumCol+=Rotate[j][i];
                    std::cout << sumCol;
                    std::cout << " ";
                    sumCol=0;
                }
                else{
                    sumCol+=Rotate[j][i];
                }
            }
        }
        
        // Calculate sums of the diagonals:
        std::cout << "OUTPUT>> Checking the sums of every diagonal:";
        diag1=0;
        diag2=0;
        for (int i=0; i<N; i++) {
            int j=i;
            if (j==(N-1)) {
                (diag1)+=Rotate[i][j];
                std::cout << (diag1);
                std::cout << " ";
            }
            else {
                (diag1)+=Rotate[i][j];
            }
        }
        
        for(int i=0; i<N;i++){
            int n=(N-i-1);
            if(i==(N-1)){
                (diag2)+=Rotate[i][n];
                std::cout << (diag2);
                std::cout << " ";
            }
            else{
                (diag2)+=Rotate[i][n];
            }
        }
        std::cout <<"\n";
        std::cout <<"\n";
        
        
        
        //STEP SIX: The fourth magic square is produced.
        
        int Spin[N][N];
        
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++){
                Spin[i][j]=Magic[j][N-i-1];
            }
        }
        // Prints out Matrix.
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++){
                std::cout <<(Spin[i][j]);
                std::cout <<" ";
            }
            std::cout <<"\n";
        }
        
        std::cout <<"\n";
        
        
        //Calculate the sums of every row:
        std::cout << "OUTPUT>> Checking the sums of every row:";
        sumRow=0;
        for( int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (j==(N-1)){
                    sumRow+= Spin[i][j];
                    cout << sumRow;
                    cout << " ";
                    sumRow=0;
                }
                else{
                    sumRow+= Spin[i][j];
                }
            }
        }
        //Calculate the sums of every column:
        std::cout << "OUTPUT>> Checking the sums of every column:";
        sumCol=0;
        for( int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (j==(N-1)){
                    sumCol+=Spin[j][i];
                    std::cout << sumCol;
                    std::cout << " ";
                    sumCol=0;
                }
                else{
                    sumCol+=Spin[j][i];
                }
            }
        }
        
        // Calculate sums of the diagonals:
        std::cout << "OUTPUT>> Checking the sums of every diagonal:";
        diag1=0;
        diag2=0;
        for (int i=0; i<N; i++) {
            int j=i;
            if (j==(N-1)) {
                (diag1)+=Spin[i][j];
                std::cout << (diag1);
                std::cout << " ";
            }
            else {
                (diag1)+=Spin[i][j];
            }
        }
        
        for(int i=0; i<N;i++){
            int n=(N-i-1);
            if(i==(N-1)){
                (diag2)+=Spin[i][n];
                std::cout << (diag2);
                std::cout << " ";
            }
            else{
                (diag2)+=Spin[i][n];
            }
        }
        std::cout <<"\n";
        std::cout <<"\n";
        
        
        //STEP SEVEN: The fifth magic square is produced.
        
        int Mirror[N][N];
        
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++){
                Mirror[i][j]=Magic[N-i-1][j];
                Mirror[N-i-1][j]=Magic[i][j];
            }
        }
        
        // Prints out Matrix.
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++){
                std::cout <<(Mirror[i][j]);
                std::cout <<" ";
            }
            std::cout <<"\n";
        }
        
        std::cout <<"\n";
        
        
        
        //Calculate the sums of every row:
        std::cout << "OUTPUT>> Checking the sums of every row:";
        sumRow=0;
        for( int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (j==(N-1)){
                    sumRow+= Mirror[i][j];
                    cout << sumRow;
                    cout << " ";
                    sumRow=0;
                }
                else{
                    sumRow+= Mirror[i][j];
                }
            }
        }
        //Calculate the sums of every column:
        std::cout << "OUTPUT>> Checking the sums of every column:";
        sumCol=0;
        for( int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (j==(N-1)){
                    sumCol+=Mirror[j][i];
                    std::cout << sumCol;
                    std::cout << " ";
                    sumCol=0;
                }
                else{
                    sumCol+=Mirror[j][i];
                }
            }
        }
        
        // Calculate sums of the diagonals:
        std::cout << "OUTPUT>> Checking the sums of every diagonal:";
        diag1=0;
        diag2=0;
        for (int i=0; i<N; i++) {
            int j=i;
            if (j==(N-1)) {
                (diag1)+=Mirror[i][j];
                std::cout << (diag1);
                std::cout << " ";
            }
            else {
                (diag1)+=Mirror[i][j];
            }
        }
        
        for(int i=0; i<N;i++){
            int n=(N-i-1);
            if(i==(N-1)){
                (diag2)+=Mirror[i][n];
                std::cout << (diag2);
                std::cout << " ";
            }
            else{
                (diag2)+=Mirror[i][n];
            }
        }
        std::cout <<"\n";
        std::cout <<"\n";
        
        
        
        // STEP EIGHT: The sixth magic square is produced.
        int Six[N][N];
        
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++){
                Six[i][j]=MirrorFlip[N-i-1][j];
                Six[N-i-1][j]=MirrorFlip[i][j];
            }
        }
        // Prints out Matrix.
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++){
                std::cout <<(Six[i][j]);
                std::cout <<" ";
            }
            std::cout <<"\n";
        }
        std::cout <<"\n";
        //Calculate the sums of every row:
        std::cout << "OUTPUT>> Checking the sums of every row:";
        sumRow=0;
        for( int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (j==(N-1)){
                    sumRow+= Six[i][j];
                    cout << sumRow;
                    cout << " ";
                    sumRow=0;
                }
                else{
                    sumRow+= Six[i][j];
                }
            }
        }
        //Calculate the sums of every column:
        std::cout << "OUTPUT>> Checking the sums of every column:";
        sumCol=0;
        for( int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (j==(N-1)){
                    sumCol+=Six[j][i];
                    std::cout << sumCol;
                    std::cout << " ";
                    sumCol=0;
                }
                else{
                    sumCol+=Six[j][i];
                }
            }
        }
        
        // Calculate sums of the diagonals:
        std::cout << "OUTPUT>> Checking the sums of every diagonal:";
        diag1=0;
        diag2=0;
        for (int i=0; i<N; i++) {
            int j=i;
            if (j==(N-1)) {
                (diag1)+= Six[i][j];
                std::cout << (diag1);
                std::cout << " ";
            }
            else {
                (diag1)+= Six[i][j];
            }
        }
        
        for(int i=0; i<N;i++){
            int n=(N-i-1);
            if(i==(N-1)){
                (diag2)+= Six[i][n];
                std::cout << (diag2);
                std::cout << " ";
            }
            else{
                (diag2)+= Six[i][n];
            }
        }
        std::cout <<"\n";
        std::cout <<"\n";
        
        // STEP NINE: The seventh magic square is produced.
        int Seven[N][N];
        
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++){
                Seven[i][j]=Spin[N-i-1][j];
                Seven[N-i-1][j]=Spin[i][j];
            }
        }
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++){
                std::cout <<(Seven[i][j]);
                std::cout <<" ";
            }
            std::cout <<"\n";
        }
        std::cout <<"\n";
        
        //Calculate the sums of every row:
        std::cout << "OUTPUT>> Checking the sums of every row:";
        sumRow=0;
        for( int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (j==(N-1)){
                    sumRow+= Seven[i][j];
                    cout << sumRow;
                    cout << " ";
                    sumRow=0;
                }
                else{
                    sumRow+= Seven[i][j];
                }
            }
        }
        //Calculate the sums of every column:
        std::cout << "OUTPUT>> Checking the sums of every column:";
        sumCol=0;
        for( int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (j==(N-1)){
                    sumCol+=Seven[j][i];
                    std::cout << sumCol;
                    std::cout << " ";
                    sumCol=0;
                }
                else{
                    sumCol+=Seven[j][i];
                }
            }
        }
        
        // Calculate sums of the diagonals:
        std::cout << "OUTPUT>> Checking the sums of every diagonal:";
        diag1=0;
        diag2=0;
        for (int i=0; i<N; i++) {
            int j=i;
            if (j==(N-1)) {
                (diag1)+= Seven[i][j];
                std::cout << (diag1);
                std::cout << " ";
            }
            else {
                (diag1)+= Seven[i][j];
            }
        }
        
        for(int i=0; i<N;i++){
            int n=(N-i-1);
            if(i==(N-1)){
                (diag2)+= Seven[i][n];
                std::cout << (diag2);
                std::cout << " ";
            }
            else{
                (diag2)+= Seven[i][n];
            }
        }
        std::cout <<"\n";
        std::cout <<"\n";
        
        // STEP TEN: The eigth magic square is produced.
        int Eight[N][N];
        
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++){
                Eight[i][j]=Rotate[N-i-1][j];
                Eight[N-i-1][j]=Rotate[i][j];
            }
        }
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++){
                std::cout <<(Eight[i][j]);
                std::cout <<" ";
            }
            std::cout <<"\n";
        }
        std::cout <<"\n";
        //Calculate the sums of every row:
        std::cout << "OUTPUT>> Checking the sums of every row:";
        sumRow=0;
        for( int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (j==(N-1)){
                    sumRow+= Eight[i][j];
                    cout << sumRow;
                    cout << " ";
                    sumRow=0;
                }
                else{
                    sumRow+= Eight[i][j];
                }
            }
        }
        //Calculate the sums of every column:
        std::cout << "OUTPUT>> Checking the sums of every column:";
        sumCol=0;
        for( int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (j==(N-1)){
                    sumCol+=Eight[j][i];
                    std::cout << sumCol;
                    std::cout << " ";
                    sumCol=0;
                }
                else{
                    sumCol+= Eight[j][i];
                }
            }
        }
        
        // Calculate sums of the diagonals:
        std::cout << "OUTPUT>> Checking the sums of every diagonal:";
        diag1=0;
        diag2=0;
        for (int i=0; i<N; i++) {
            int j=i;
            if (i==(N-1)) {
                (diag1)+= Eight[i][j];
                std::cout << (diag1);
                std::cout << " ";
            }
            else {
                (diag1)+=Eight[i][j];
            }
        }
        
        for(int i=0; i<N;i++){
            int n=(N-i-1);
            if(i==(N-1)){
                (diag2)+=Eight[i][n];
                std::cout << (diag2);
                std::cout << " ";
            }
            else{
                (diag2)+=Eight[i][n];
            }
        }
        std::cout <<"\n";
        std::cout <<"\n";
    }
}
