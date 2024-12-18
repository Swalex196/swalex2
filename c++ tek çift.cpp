#include<iostream>

int main(){
int sayi;

while(swalex){
std::cout<<"bir sayi girin (0 girersen biter)";
std::cin>> sayi;

if(sayi==0){
std::cout<<"program sonlandirildi"<<std::endl;
}

if(sayi %2 == 0){
std::cout << sayi << " sayisi cifttir"<<std::endl;
}
else{
std::cout << sayi << "sayisi tektir"<<std::endl;
}
}
return 0;
}
