#include <iostream>
#include <fstream>
#include <cstdio>
#include <windows.h>
#include <iomanip>
#include <locale.h>
#include <cmath>
#include <conio.h>
#define PI 3.14159265

using namespace std;

void excluir();
int FluxoV(double R, double G);
void Retangulo(double A, double B);
void Triangulo(double A, double B);
int Terreno(int A);
void cadastrar();
void listar ();
void pesquisar ();
void editar();

struct dados {
	char Pais[200], Estado[200],Cidade[200],NomeEmpresa[200],Terreno[200],LONG[11],LAT[10],MER[100],OPT[100];
	double LargT, CompT, FluxoV,G1,G2,G3,G4,Vv,P;
	long long int NG;
	int status;
}; dados empresa;

fstream arquivo;

void editar(){
	
	system("cls");
cout<< "\t\t------------------------------------------------"<<endl;
cout<< "\t\t|                                              |"<<endl;
cout<< "\t\t|         >EDITAR EMPRESA CADASTRADAS<         |"<<endl;
cout<< "\t\t|                                              |"<<endl;
cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
	arquivo.clear();
	cin.ignore();
	char n[100];
	bool encontrado = false;
	cout<<"\tDIGITE O NOME DA EMPRESA: ";
	cin.getline(n,100);
	arquivo.seekg(0,arquivo.beg);
	arquivo.read((char*)&empresa, sizeof(empresa));

		
		while(!arquivo.eof()){
			
			
			if(strcmp(empresa.NomeEmpresa,n)==0 && empresa.status == 0 && encontrado==false){
			
			cout<<"\t Pa�s: ";
			cin.getline(empresa.Pais,200);
			cout<<"\t Nome da Empresa: ";
			cin.getline(empresa.NomeEmpresa,200);
			cout<<"\t LATITUDE: ";
			cin>>empresa.LAT;
			cout<<"\t LONGITUDE: ";
			cin>>empresa.LONG;
			
			encontrado = true;
			
			arquivo.seekp(arquivo.tellp() - sizeof(empresa),arquivo.beg);
			arquivo.write((char *)& empresa, sizeof(empresa));
			
			}
		arquivo.read((char*)&empresa, sizeof(empresa));
		}
		system("pause");
}

void excluir(){
	system("cls");
		cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|              >EXCLUIR EMPRESA<               |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
	cin.ignore();
	arquivo.clear();
	char nomeprocura[100];
	
	cout<<"DIGITE O NOME DA EMPRESA: ";
	cin.getline(nomeprocura,100);
	arquivo.seekg(0,arquivo.beg);
	arquivo.read((char*)&empresa,sizeof(empresa));
	bool encontrado=false;
	
	while(!arquivo.eof()){
			if(strcmp(nomeprocura,empresa.NomeEmpresa)==0 && empresa.status == 0){
			encontrado=true;
	   	   	empresa.status = 1;
			cout<<endl;
			cout<<"PA�S: "<<empresa.Pais<<endl;
			cout<<"NOME DA EMPRESA: "<<empresa.NomeEmpresa<<endl;
			cout<<"LATITUDE: "<<empresa.LAT<<endl;
			cout<<"LONGITUDE: "<<empresa.LONG<<endl;
			cout<<"FORMATO DO TERRENO: "<<empresa.Terreno<<endl;			
			cout<<"FLUXO DE VENTO DO TERRENO: "<<empresa.FluxoV<<endl;
			cout<<endl;
			arquivo.seekp(arquivo.tellp()-sizeof(empresa));
			arquivo.write((char*)&empresa, sizeof(empresa)); 
			}
		arquivo.read((char*)&empresa,sizeof(empresa));
	}
	if(!encontrado){
		cout<<endl<<endl<<endl;
	 cout << "\t\t\t     EMPRESA N�O ENCONTRADA!"<<endl<<endl<<endl;}
  
	else cout <<"\t\t\t     EMPRESA EXCLUIDA COM SUCESSO! "<< endl<<endl;
  
	remove("produtos.txt");
	system("pause");
		
}
int FluxoV(double R,double G){
	double cp = 0.59, p = 1.2;
	long long int Area,M = 0;
	arquivo.clear();
	
	system("cls");
	
		cout<< "\t\t------------------------------------------------------"<<endl;
        cout<< "\t\t|                    ESCALA BEAUFORT                 |"<<endl;
        cout<< "\t\t|-----------|-------|--------------------------------|"<<endl;
        cout<< "\t\t|VELOCIDADE | [M/S] |          CAPACIDADE            |"<<endl;
        cout<< "\t\t|-----------|-------|--------------------------------|"<<endl;
        cout<< "\t\t|+ CALMO    | < 0.3 | MAU FUNCIONAMENTO DAS TURBINAS |"<<endl;
        cout<< "\t\t|-----------|-------|--------------------------------|"<<endl;
        cout<< "\t\t|+ ARAGEM   |0.3-1.5|            XXXX                |"<<endl;
        cout<< "\t\t|-----------|-------|--------------------------------|"<<endl;
        cout<< "\t\t|+BRISA LEVE|1.6-3.3|            XXXX                |"<<endl;
        cout<< "\t\t|-----------|-------|--------------------------------|"<<endl;
        cout<< "\t\t|+ BRISA    |3.4-5.4|                                |"<<endl;
        cout<< "\t\t|  FRACA    |       |            XXXX                |"<<endl;
        cout<< "\t\t|-----------|-------|--------------------------------|"<<endl;
        cout<< "\t\t|+ BRISA    |5.5-7.9|VELOCIDADE M�XIMA DE UMA TURBINA|"<<endl;
        cout<< "\t\t|  MODERADA |       |M�DIA GRANDE/GRANDE             |"<<endl;
		cout<< "\t\t|-----------|-------|--------------------------------|"<<endl;
        cout<< "\t\t|+ BRISA    |8.0 -  |VELOCIDADE M�XIMA DE UMA TURBINA|"<<endl;
        cout<< "\t\t|  FORTE    |10.7   |PEQUENO                         |"<<endl;
		cout<< "\t\t|-----------|-------|--------------------------------|"<<endl;    
		cout<< "\t\t|+ VENTO    |10.8 - |VELOCIDADE M�XIMA DE UMA TURBINA|"<<endl;
		cout<< "\t\t|  FRESCO   |13.8   |M�DIO                           |"<<endl;
        cout<< "\t\t|-----------|-------|--------------------------------|"<<endl;   
		cout<< "\t\t|+ VENTO    |13.9 - |                                |"<<endl;
  		cout<< "\t\t|  FORTE    |17.1   |            XXXX                |"<<endl;
		cout<< "\t\t|-----------|-------|--------------------------------|"<<endl; 
    	cout<< "\t\t|+ XXXX     | >17.1 | MAU FUNCIONAMENTO DAS TURBINAS |"<<endl;       
        cout<< "\t\t------------------------------------------------------"<<endl<<endl<<endl;

	do{	
	 cout<<"FLUXO DE VENTO DO TERRENO: ";
	cin>>empresa.Vv;
	cout<<endl;
	}while(empresa.Vv<0 && empresa.Vv>17.1);
		
		Area = PI*pow(R,2);
	 
	 empresa.P= cp*1/2*p*Area*pow(empresa.Vv,3);
 	 
	cout<<"POTENCIA DE UM GERADOR: "<<empresa.P<<"[W]"<<endl<<endl;
	empresa.NG = (empresa.P*G);
	cout<<fixed<<setprecision(4)<<"POTENCIA DE TODOS OS GERADORES DO TERRENO: "<<empresa.NG<<"[W]"<<endl<<endl;

system("pause");	
}
void Trapezio(double A, double B, double BM){
 double G0,CirculosRetangulo,BaseTriangulo,ANG,BM1,AM,T,REL,G = 0,R,R1,R2,R3,R4;
int Op,j;

for(j=1;j<=4;j++){
	if(j==1){
  		cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|                TURBINA PEQUENA               |"<<endl;
        cout<< "\t\t|----------------------------------------------|"<<endl;
        cout<< "\t\t|#DIAMETRO: 17 METROS                          |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#ESPA�O DE SEGURAN�A DAS TURBINAS: 4 METROS   |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#POTENCIA MAXIMA: 50000[W]                    |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#FLUXO DE VENTO MAXIMO SUPOTADO: 8.5 [M/S]    |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
	R = 12.5;	
	}
	if(j==2){
  		cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|                TURBINA M�DIA                 |"<<endl;
        cout<< "\t\t|----------------------------------------------|"<<endl;
        cout<< "\t\t|#DIAMETRO: 21 METROS                          |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#ESPA�O DE SEGURAN�A DAS TURBINAS: 5 METROS   |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#POTENCIA MAXIMA: 100000[W]                   |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#FLUXO DE VENTO MAXIMO SUPOTADO: 9.5 [M/S]    |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
	R = 15.5;
	}
	if(j==3){
  		cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|              TURBINA M�DIA GRANDE            |"<<endl;
        cout<< "\t\t|----------------------------------------------|"<<endl;
        cout<< "\t\t|#DIAMETRO: 63 METROS                          |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#ESPA�O DE SEGURAN�A DAS TURBINAS: 15 METROS  |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#POTENCIA MAXIMA: 550000[W]                   |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#FLUXO DE VENTO MAXIMO SUPOTADO: 8.0 [M/S]    |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;	
	R = 46.5;
	}
	if(j==4){
  		cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|                TURBINA GRANDE                |"<<endl;
        cout<< "\t\t|----------------------------------------------|"<<endl;
        cout<< "\t\t|#DIAMETRO: 126 METROS                         |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#ESPA�O DE SEGURAN�A DAS TURBINAS: 20 METROS  |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#POTENCIA MAXIMA: 1000000[W]                  |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#FLUXO DE VENTO MAXIMO SUPOTADO: 7.0 [M/S]    |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
	R = 83;
	}
	
 BaseTriangulo = B - BM;
 CirculosRetangulo = floor(A/(2*R)) * floor(BM /(2*R));
 ANG =  atan (A/B) * 180 / PI;
 BM1 = R/tan((ANG/2)*PI/180) + R;
 AM = (A/BaseTriangulo) * BM1;
 T = floor(A/(2*R));
 REL = BaseTriangulo/A;
 G = G + T;
 for(int i=1;i<=T;i++){
  if (i == 1)
   G = G + floor((BaseTriangulo - i*BM1)/(2*R));
  else 
   G = G + floor((BaseTriangulo - i*BM1 + (i-1)*REL*(AM-2*R))/(2*R));
 }
 G0 = CirculosRetangulo + G;
   
    if(j==1)empresa.G1 = G0;
	if(j==2)empresa.G2 = G0;
	if(j==3)empresa.G3 = G0;
	if(j==4)empresa.G4 = G0;
	cout<<endl;	
	cout<<"QUANTIDADE DE GERADORES: "<<G0<<endl;	
	cout<<endl;
	system("Pause");
	cout<<endl;
 }
 	do{
		cout<<endl;
		cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|           QUAL GERADOR DESEJA?               |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
    	cout<<endl; 
 		cout<<"\t\t\t\t1 - GERADOR PEQUENO"<<endl;
		cout<<"\t\t\t\t2 - GERADOR M�DIO"<<endl;
		cout<<"\t\t\t\t3 - GERADOR M�DIO GRANDE"<<endl;
		cout<<"\t\t\t\t4 - GERADOR GRANDE"<<endl;
		cout<<"\t\t\t\t5 - SAIR"<<endl;
		cout<<"\t\tESCOLHA UM OP��O: ";
		cin>>Op;
		switch(Op){
			
			case 1:
				R1 = 8.5;
			FluxoV(R1,empresa.G1);
				break;
		
			case 2:
				R2 = 10.5;
			FluxoV(R2,empresa.G2);
				break;
			
			case 3:
				R3 = 31.5;
			FluxoV(R3,empresa.G3);
				break;
		
			case 4:
				R4 = 63;
			FluxoV(R4,empresa.G4);
				break;						
		   	
			default:
				
	   			break;
		}
	system("cls");
	}while(Op!=5);

}

void Retangulo(double A, double B){
double R,R1,R2,R3,R4,G;
int Op;

for(int i=1;i<=4;i++){
    G = 0;
	if(i==1){
  		cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|                TURBINA PEQUENA               |"<<endl;
        cout<< "\t\t|----------------------------------------------|"<<endl;
        cout<< "\t\t|#DIAMETRO: 17 METROS                          |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#ESPA�O DE SEGURAN�A DAS TURBINAS: 4 METROS   |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#POTENCIA MAXIMA: 50000[W]                    |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#FLUXO DE VENTO MAXIMO SUPOTADO: 8.5 [M/S]    |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
	R = 12.5;	
	}
	if(i==2){
  		cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|                TURBINA M�DIA                 |"<<endl;
        cout<< "\t\t|----------------------------------------------|"<<endl;
        cout<< "\t\t|#DIAMETRO: 21 METROS                          |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#ESPA�O DE SEGURAN�A DAS TURBINAS: 5 METROS   |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#POTENCIA MAXIMA: 100000[W]                   |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#FLUXO DE VENTO MAXIMO SUPOTADO: 9.5 [M/S]    |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
	R = 15.5;
	}
	if(i==3){
  		cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|              TURBINA M�DIA GRANDE            |"<<endl;
        cout<< "\t\t|----------------------------------------------|"<<endl;
        cout<< "\t\t|#DIAMETRO: 63 METROS                          |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#ESPA�O DE SEGURAN�A DAS TURBINAS: 15 METROS  |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#POTENCIA MAXIMA: 550000[W]                   |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#FLUXO DE VENTO MAXIMO SUPOTADO: 8.0 [M/S]    |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;	
	R = 46.5;
	}
	if(i==4){
  		cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|                TURBINA GRANDE                |"<<endl;
        cout<< "\t\t|----------------------------------------------|"<<endl;
        cout<< "\t\t|#DIAMETRO: 126 METROS                         |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#ESPA�O DE SEGURAN�A DAS TURBINAS: 20 METROS  |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#POTENCIA MAXIMA: 1000000[W]                  |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#FLUXO DE VENTO MAXIMO SUPOTADO: 7.0 [M/S]    |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
	R = 83;
	}

 G = floor(A/(2*R)) * floor(B /(2*R));
 
 	if(i==1)empresa.G1 = G;
	if(i==2)empresa.G2 = G;
	if(i==3)empresa.G3 = G;
	if(i==4)empresa.G4 = G;
	cout<<endl;	
	cout<<"QUANTIDADE DE GERADORES: "<<G<<endl;	
	cout<<endl;
	system("Pause");
	cout<<endl;
 }
 	do{
		cout<<endl;
		cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|           QUAL GERADOR DESEJA?               |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
    	cout<<endl; 
 		cout<<"\t\t\t\t1 - GERADOR PEQUENO"<<endl;
		cout<<"\t\t\t\t2 - GERADOR M�DIO"<<endl;
		cout<<"\t\t\t\t3 - GERADOR M�DIO GRANDE"<<endl;
		cout<<"\t\t\t\t4 - GERADOR GRANDE"<<endl;
		cout<<"\t\t\t\t5 - SAIR"<<endl;
		cout<<"\t\tESCOLHA UM OP��O: ";
		cin>>Op;
		switch(Op){
			
			case 1:
				R1 = 8.5;
			FluxoV(R1,empresa.G1);
				break;
		
			case 2:
				R2 = 10.5;
			FluxoV(R2,empresa.G2);
				break;
			
			case 3:
				R3 = 31.5;
			FluxoV(R3,empresa.G3);
				break;
		
			case 4:
				R4 = 63;
			FluxoV(R4,empresa.G4);
				break;						
		   	
			default:
				
	   			break;
		}
	system("cls");
	}while(Op!=5);
}

void Triangulo(double L1, double L2, double A){
	double B1,B2,ANG1,ANG2,R,BM1,BM2,AM,T,REL1,REL2,G,D1,R1,R2,R3,R4,D2;
	int Op;
	for(int i=1;i<=4;i++){
    G = 0;
	if(i==1){
  		cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|                TURBINA PEQUENA               |"<<endl;
        cout<< "\t\t|----------------------------------------------|"<<endl;
        cout<< "\t\t|#DIAMETRO: 17 METROS                          |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#ESPA�O DE SEGURAN�A DAS TURBINAS: 4 METROS   |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#POTENCIA MAXIMA: 50000[W]                    |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#FLUXO DE VENTO MAXIMO SUPOTADO: 8.5 [M/S]    |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
	R = 12.5;	
	}
	if(i==2){
  		cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|                TURBINA M�DIA                 |"<<endl;
        cout<< "\t\t|----------------------------------------------|"<<endl;
        cout<< "\t\t|#DIAMETRO: 21 METROS                          |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#ESPA�O DE SEGURAN�A DAS TURBINAS: 5 METROS   |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#POTENCIA MAXIMA: 100000[W]                   |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#FLUXO DE VENTO MAXIMO SUPOTADO: 9.5 [M/S]    |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
	R = 15.5;
	}
	if(i==3){
  		cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|              TURBINA M�DIA GRANDE            |"<<endl;
        cout<< "\t\t|----------------------------------------------|"<<endl;
        cout<< "\t\t|#DIAMETRO: 63 METROS                          |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#ESPA�O DE SEGURAN�A DAS TURBINAS: 15 METROS  |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#POTENCIA MAXIMA: 550000[W]                   |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#FLUXO DE VENTO MAXIMO SUPOTADO: 8.0 [M/S]    |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;	
	R = 46.5;
	}
	if(i==4){
  		cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|                TURBINA GRANDE                |"<<endl;
        cout<< "\t\t|----------------------------------------------|"<<endl;
        cout<< "\t\t|#DIAMETRO: 126 METROS                         |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#ESPA�O DE SEGURAN�A DAS TURBINAS: 20 METROS  |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#POTENCIA MAXIMA: 1000000[W]                  |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|#FLUXO DE VENTO MAXIMO SUPOTADO: 7.0 [M/S]    |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
	R = 83;
	}

	B1 = sqrt(pow(L1,2) - pow(A,2));
	B2 = sqrt(pow(L2,2) - pow(A,2));
	ANG1 =  atan (A/B1) * 180 / PI;
	BM1 = R/tan((ANG1/2)*PI/180) + R;
	AM = (A/B1) * BM1;
	T = floor(A/(2*R));
	REL1 = B1/A;
	G = G + T;
	for(int i=1;i<=T;i++){
		if (i == 1)
			G = G + floor((B1 - i*BM1)/(2*R));
		else 
			G = G + floor((B1 - i*BM1 + (i-1)*REL1*(AM-2*R))/(2*R));
	}
	ANG2 =  atan (A/B2) * 180 / PI;
	BM2 = R/tan((ANG2/2)*PI/180) + R;
	AM = (A/B2) * BM2;
	T = floor(A/(2*R));
	REL2 = B2/A;
	G = G + T;
	for(int i=1;i<=T;i++){
		if (i == 1)
			G = G + floor((B2 - i*BM2)/(2*R));
		else 
			G = G + floor((B2 - i*BM2 + (i-1)*REL2*(AM-2*R))/(2*R));
	}
	for(int i=1;i<=T;i++){
		if (i == 1){
			D1 = B1 - floor((B1 - i*BM1)/(2*R)) - BM1;
			D2 = B2 - floor((B2 - i*BM2)/(2*R)) - BM2;
			if(D1+D2>=2*R) G++;
		}
		else{ 
		   	D1 = B1 - floor((B1 - i*BM1 + (i-1)*REL1*(AM-2*R))/(2*R)) - BM1;
		   	D2 = B2 - floor((B1 - i*BM2 + (i-1)*REL2*(AM-2*R))/(2*R)) - BM2;
		   	if(D1 + D2>=2*R) G++;
		}
	}
	if(i==1)empresa.G1 = G;
	if(i==2)empresa.G2 = G;
	if(i==3)empresa.G3 = G;
	if(i==4)empresa.G4 = G;
	cout<<endl;	
	cout<<"QUANTIDADE DE GERADORES: "<<G<<endl;	
	cout<<endl;
	system("Pause");
	cout<<endl;
}

	do{
		cout<<endl;
		cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|           QUAL GERADOR DESEJA?               |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
    	cout<<endl; 
 		cout<<"\t\t\t\t1 - GERADOR PEQUENO"<<endl;
		cout<<"\t\t\t\t2 - GERADOR M�DIO"<<endl;
		cout<<"\t\t\t\t3 - GERADOR M�DIO GRANDE"<<endl;
		cout<<"\t\t\t\t4 - GERADOR GRANDE"<<endl;
		cout<<"\t\t\t\t5 - SAIR"<<endl;
		cout<<"\t\tESCOLHA UM OP��O: ";
		cin>>Op;
		switch(Op){
			
			case 1:
				R1 = 8.5;
			FluxoV(R1,empresa.G1);
				break;
		
			case 2:
				R2 = 10.5;
			FluxoV(R2,empresa.G2);
				break;
			
			case 3:
				R3 = 31.5;
			FluxoV(R3,empresa.G3);
				break;
		
			case 4:
				R4 = 63;
			FluxoV(R4,empresa.G4);
				break;						
		   	
			default:
				
	   			break;
		}
	system("cls");
	}while(Op!=5);
		
	}		


int Terreno(int A){
	double CompT, LargT, Areat, CompT1,CompMT;
	int Opcao;
	system("cls");
    A = 1;
		do{
		Opcao = 0;
		cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|                  >TERRENO<                   |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
      
    	cout<<endl; 
		cout<<"\t\t\t\t1 - RET�NGULO"<<endl;
		cout<<"\t\t\t\t2 - TRAP�ZIO"<<endl;
		cout<<"\t\t\t\t3 - TRI�NGULO"<<endl;
		cout<<"\t\t\t\t4 - SAIR"<<endl;
		cout<<endl;
		cout<<"ESCOLHA UMA OP��O: ";
	   	cin>>Opcao;
	   	cout<<endl; 
	   	system("cls");
	  	
		if(Opcao == 1){

		cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|                   >AREA<                     |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
	     	cout<<"LARGURA DO TERRENO: ";
		   	cin>>CompT;
	  	   	cout<<"ALTURA DO TERRENO: ";
	   		cin>>LargT;
	  	    	system("cls");
		}
		if(Opcao == 2){

		cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|                   >AREA<                     |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
	     	cout<<"BASE MAIOR DO TERRENO: ";
		   	cin>>CompT;
   			cout<<"BASE MENOR DO TERRENO: ";
		   	cin>>CompT1;
	  	   	cout<<"ALTURA DO TERRENO: ";
	   		cin>>LargT;
	  	    	system("cls");
		}
		if(Opcao == 3){
			   		
	    cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|                   >AREA<                     |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;	

		   	do{
			cout<<"Lateral esquerda do terreno: ";
		   	cin>>CompT;
		   	cout<<"Lateral direita do terreno: ";
		   	cin>>CompT1;
	  	   	cout<<"Altura do terreno: ";
	   		cin>>LargT;
			}while(CompT<=LargT && CompT1<=LargT && CompT>=0 && CompT1 >= 0 && LargT>= 0);
	  	    	system("cls");	
		}
	   	   	
		
		switch(Opcao){
		
		case 1:
			cout<< "\t\t\t    -------------------"<<endl;
    	    cout<< "\t\t\t    |   > RET�NGULO < |"<<endl;
    	    cout<< "\t\t\t    -------------------"<<endl<<endl<<endl;
    	    strcpy(empresa.Terreno,"Ret�ngular");
			Retangulo(CompT,LargT);	
				break;
		
		case 2:
		   	cout<< "\t\t\t    -------------------"<<endl;
        	cout<< "\t\t\t    |   > TRAP�ZIO <  |"<<endl;
			cout<< "\t\t\t    -------------------"<<endl<<endl<<endl;
		   	strcpy(empresa.Terreno,"Trapezoidal");
		   	Trapezio(LargT,CompT,CompT1);
				break;
			
		case 3:
	  		cout<< "\t\t\t      --------------------"<<endl;
			cout<< "\t\t\t      |   > TRI�NGULO <  |"<<endl;
		   	cout<< "\t\t\t      --------------------"<<endl<<endl<<endl;
	 		strcpy(empresa.Terreno,"Tri�ngular");
			Triangulo(CompT,CompT1,LargT);
				break;
		}
		system("cls");	
	}while(Opcao !=4);
return A;
}

void cadastrar(){
	int B = 0,Op,V = 0,CR=0,TamV=0,RV,tam1 = 0,tam = 0;
	char NE[200],X[10],Y[11];	
	
	system("cls");
	cin.ignore();
	arquivo.clear();
cout<< "\t\t------------------------------------------------"<<endl;
cout<< "\t\t|                                              |"<<endl;
cout<< "\t\t|                  >CADASTRO<                  |"<<endl;
cout<< "\t\t|                                              |"<<endl;
cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
		
	
	cout<<"\t# NOME DA EMPRESA: ";
	cin.getline(NE,200);
	arquivo.clear();
	arquivo.seekg(0,arquivo.beg);
	arquivo.read((char*)&empresa,sizeof(empresa));
		
			while(!arquivo.eof()){
			   	if(strcmp(NE,empresa.NomeEmpresa)==0){
			   			cout<<endl;
					   	cout<<"\t\t\t    EMPRESA JA CADASTRADA!"<<endl<<endl;
					   	CR = 1;
						system("Pause");
				}
			arquivo.read((char*)&empresa,sizeof(empresa));
			}
		arquivo.clear();
		if(CR==1)return;
		strcpy(empresa.NomeEmpresa,NE);	
	cout<<endl;
	cout<<"\t# PA�S: ";
	cin.getline(empresa.Pais,200);
	

	cout<<endl;
	cout<<"\t# LATITUDE: (0� at� 90�) "<<endl;
	cout<<"\t----------------------------------------"<<endl;
	cout<<"\t|+ EXEMPLO PARA DIGITAR 90X60X60X        |"<<endl;
	cout<<"\t|+ X - ESPA�O ENTRE OS NUMEROS DIGITADOS |"<<endl;
	cout<<"\t----------------------------------------"<<endl;
	cout<<"\t- ";
	cin.getline(X,10);
	tam = strlen(X);
	X[2]='�';
	X[5]='"';
	X[8]='�';
	cout<<endl;
	cout<<"\t# SUA LATITUDE: ";
	for(int i=0; i<tam; i++)
	X[i];
	strcpy(empresa.LAT,X);
    cout<<X;
	
	cout<<endl<<endl;
	
	cout<<"\t      1 - SUL"<<endl;
	cout<<"\t      2 - NORTE"<<endl<<endl;
		
		do{
			
			cout<<"\t      - ";
			cin>>RV;
			
		
		   	switch(RV){
				   
			case 1:
		   	cout<<"\t\t# PARA O SUL"<<endl;
		   	strcpy(empresa.MER,"SUL");
		   	cout<<endl;
		   	break;
	
			case 2:
		   	cout<<"\t\t# PARA O NORTE"<<endl;
		   	strcpy(empresa.MER,"NORTE");
		   	cout<<endl;
		   	break;
	
			default:
			cout<<"\t\t\t    ESCOLHA INVALIDA!"<<endl;
			break;
			}
		
		}while(RV!=1 && RV!=2);

	
	
	cout<<endl;
    cin.ignore();
	cout<<"\t# LONGITUDE: (0� at� 180�) "<<endl;
	cout<<"\t------------------------------------------"<<endl;
	cout<<"\t|+ EXEMPLO PARA DIGITAR 180X60X60X       |"<<endl;
	cout<<"\t|+ X - ESPA�O ENTRE OS NUMEROS DIGITADOS |"<<endl;
	cout<<"\t------------------------------------------"<<endl;
	cout<<"\t- ";
	
	cin.getline(Y,10);
	
	tam1 = strlen(Y);
	
	Y[3]='�';
	Y[6]='"';
	Y[9]='�';
	Y[10]='\0';
	cout<<endl;
	cout<<"\t# SUA LONGITUDE: ";
	for(int j=0; j<tam1; j++)
    Y[j];
	strcpy(empresa.LONG,Y);
	cout<<Y;
	cin.ignore();
	
	cout<<endl<<endl;
	
	cout<<"\t     1 - LESTE"<<endl;
	cout<<"\t     2 - OESTE"<<endl;
	
	do{
		cout<<"\t- ";
		cin>>RV;
	
	
	
	switch(RV){
	
	case 1:
		cout<<endl;
		cout<<"\t\t# PARA O LESTE"<<endl;
		strcpy(empresa.OPT,"LESTE");
		cout<<endl;
		break;
	
	case 2:
		cout<<endl;
		cout<<"\t\t# PARA O OESTE"<<endl;
		strcpy(empresa.OPT,"OESTE");
		cout<<endl;
		break;
	
	default:
		cout<<"\t\t\t    ESCOLHA INVALIDA!"<<endl;
		break;
	
	}
	
	}while(RV!=1 && RV!=2);	
	

	
	system("Pause");
	empresa.status = 0;
	cin.ignore();
	do{
		
		system("cls"); 
	cout<< "\t-------------------------------------------------------------------"<<endl;
	cout<< "\t|                                                                 |"<<endl;
	cout<< "\t| > DESEJA CALCULAR A QUANTIDADE DE GERADORES PARA SEU TERRENO? < |"<<endl;
	cout<< "\t|                                                                 |"<<endl;
	cout<< "\t-------------------------------------------------------------------"<<endl<<endl<<endl;
	
		cout<<"\t\t#1 - Sim"<<endl;
		cout<<"\t\t#2 - N�o"<<endl;
		cout<<endl;
	   	cout<<"\t\t - ESCOLHA UM OP��O: ";
	    cin>>Op;
		cout<<endl;
		switch(Op){
		case 1:
		V=Terreno(B);
			break;
		case 2:
        if(V==1){
		cout<<"\t\t\tEMPRESA CADASTRADA COM SUCESSO!"<<endl;
		system("pause");
		}
		else V = 0;
		break;
		
		default:
			cout<<"\t\t\tESCOLHA INVALIDA!"<<endl;
	   		cout<<endl;
    			system("pause");
		break;
		}
		
	}while(Op!=2);
	
	
	arquivo.seekp(0,arquivo.end);
	arquivo.write((char*)&empresa, sizeof(empresa));
		
	if(V==0){
	cout<<"CADASTRO INCONPLETO!"<<endl;
	system("pause");
	}

}



void listar(){

	system("cls");
	arquivo.clear();
	arquivo.seekg(0,arquivo.beg);
	arquivo.read((char*)&empresa,sizeof(empresa));
cout<< "\t\t------------------------------------------------"<<endl;
cout<< "\t\t|                                              |"<<endl;
cout<< "\t\t|        >LISTA DE EMPRESAS CADASTRADAS<       |"<<endl;
cout<< "\t\t|                                              |"<<endl;
cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
	while(!arquivo.eof()){
			if(empresa.status == 0){
		
			cout<<"PA�S: "<<empresa.Pais<<endl;
			cout<<"NOME DA EMPRESA: "<<empresa.NomeEmpresa<<endl;
			cout<<"LATITUDE: "<<empresa.LAT<<" PARA O "<<empresa.MER<<endl;
			cout<<"LONGITUDE: "<<empresa.LONG<<" PARA O "<<empresa.OPT<<endl;
			cout<<"FORMATO DO TERRENO: "<<empresa.Terreno<<endl;
			cout<<"FLUXO DE VENTO DO TERRENO: "<<empresa.Vv<<endl;
			cout<<"POT�NCIA TOTAL GERADA PELA FAZENDA: "<<empresa.NG<<endl;
			cout<<endl;
			
			}
		arquivo.read((char*)&empresa,sizeof(empresa));
	}
	
	system("pause");
}


void pesquisar(){
	
	system("cls"); //limpar a tela.
	arquivo.clear();
	arquivo.seekg(0,arquivo.beg);
	arquivo.read((char*)&empresa,sizeof(empresa));
	
	char n[100];
cout<< "\t\t------------------------------------------------"<<endl;
cout<< "\t\t|                                              |"<<endl;
cout<< "\t\t|        >PESQUISAR EMPRESAS CADASTRADAS<      |"<<endl;
cout<< "\t\t|                                              |"<<endl;
cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
	cin.ignore();
	cout<<"NOME DA EMPRESA: ";
	cin.getline(n,100);
	cout<<endl;

	while(!arquivo.eof()){
		if(strcmp(empresa.NomeEmpresa,n) == 0){
			
			cout<<"\tPA�S: "<<empresa.Pais<<endl;
			cout<<"\tNOME DA EMPRESA: "<<empresa.NomeEmpresa<<endl;
			cout<<"\tLATITUDE: "<<empresa.LAT<<" PARA O "<<empresa.MER<<endl;
			cout<<"\tLONGITUDE: "<<empresa.LONG<<" PARA O "<<empresa.OPT<<endl;
		}
		arquivo.read((char*)&empresa,sizeof(empresa));
	}
	
	system("pause");
}

int main(){
int opcao;
	
	setlocale(LC_ALL,"Portuguese");
	arquivo.open("BancoDeDados.txt",ios::in | ios::out | ios::binary); 
	if(arquivo.is_open() == false)
		arquivo.open("BancoDeDados.txt", ios::in | ios::out | ios::trunc | ios::binary); // trunc para criar uma nova pasta BancoDeDados caso ela seja apagada.
do{
		
		arquivo.clear(); //resetar ponteiro.
		system("cls"); //limpar a tela.
		cout<<endl;
    	cout<< "\t\t------------------------------------------------"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|                     MENU                     |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|----------------------------------------------|"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t|                   INATEL                     |"<<endl;
        cout<< "\t\t|             	                               |"<<endl;
        cout<< "\t\t|                FAZENDA E�LICA                |"<<endl;
        cout<< "\t\t|                                              |"<<endl;
        cout<< "\t\t------------------------------------------------"<<endl<<endl<<endl;
		cout<<"\t\t\t\t1 - CADASTRAR"<<endl;
		cout<<"\t\t\t\t2 - LISTAR"<<endl;
		cout<<"\t\t\t\t3 - PESQUISAR"<<endl;
		cout<<"\t\t\t\t4 - EXCLUIR"<<endl;
		cout<<"\t\t\t\t5 - EDITAR"<<endl;
		cout<<"\t\t\t\t6 - SAIR"<<endl;
		
		
		cout<<endl;
		cout<<"ESCOLHA UMA OP��O: ";
		cin>>opcao;
		
		switch(opcao){
			case 1:
				cadastrar();
				break;
			
			case 2:
				listar();
				break;
			case 3:
				pesquisar();
				break;
			case 4:
				excluir();
				break;
			case 5:
				editar();
				break;
			
		}
	
	}while(opcao !=6);
	
	if(opcao == 6){
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"\t\t\tOBRIGADO PELA PREFER�NCIA"<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
	}
	
	arquivo.close();
		
}	

