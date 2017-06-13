#include<iostream>
using namespace std;

int numberOfLadyShimp;
int numberOfShimp;
int ladyShimpHeights[50001];
int tempLadyShimpHeights[50001];
int shimpHeights[25001];


void readInput(){
	cin >> numberOfLadyShimp;
	for(int i=0;i<numberOfLadyShimp;i++){
		cin >> tempLadyShimpHeights[i];
	}
	cin >> numberOfShimp;
	for(int i =0; i< numberOfShimp; i++){
		cin >> shimpHeights[i];
	}
	
	int j = 0;
	for(int i =0; i< numberOfLadyShimp;i++){
		
		if(i == 0){
			ladyShimpHeights[j++] = tempLadyShimpHeights[i];
		}else if(tempLadyShimpHeights[i] != tempLadyShimpHeights[i-1]){
		    ladyShimpHeights[j++] = tempLadyShimpHeights[i];
		}
	}
	numberOfLadyShimp = j;
}

int main(){
 readInput();
 for(int i =0; i < numberOfShimp; i++){
	int startIndex, endIndex, midIndex;
	startIndex = 0;
	endIndex = numberOfLadyShimp -1;
	int matchingIndex = -1;
	
	int currentShimpHeight = shimpHeights[i];
	while(startIndex <= endIndex){
		midIndex = (startIndex + endIndex)/2;
		
		if(currentShimpHeight > ladyShimpHeights[midIndex]){
			startIndex = midIndex + 1;
		}else if(currentShimpHeight < ladyShimpHeights[midIndex]){
			endIndex = midIndex - 1;
		}else{
			matchingIndex = midIndex;
		  break;
		}
	}
	
	if(matchingIndex != -1){
	   if(matchingIndex == 0 && matchingIndex == numberOfLadyShimp -1){
			cout << "X X";
	   } 
	   else if(matchingIndex == 0){
			cout << "X " << ladyShimpHeights[matchingIndex+1];
	   }else if(matchingIndex == numberOfLadyShimp -1){
			cout << ladyShimpHeights[matchingIndex -1] << " X";
	   }else {
			cout << ladyShimpHeights[matchingIndex -1] << " " << ladyShimpHeights[matchingIndex + 1];
	   }
	}else{
	    if(endIndex >= 0 && startIndex <= numberOfLadyShimp-1){
			cout << ladyShimpHeights[endIndex] << " " << ladyShimpHeights[startIndex];
		}
		else if(endIndex < 0 && startIndex <= numberOfLadyShimp-1){
			cout << "X " << ladyShimpHeights[startIndex];
		}
		else if(endIndex >= 0 && startIndex > numberOfLadyShimp-1){
			cout << ladyShimpHeights[endIndex] << " X";
		}
	}
	cout << endl;
 }
return 0;
}