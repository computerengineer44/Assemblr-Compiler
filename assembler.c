#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

/*
BUÐRA ENHAR ELBÝR
02200201072
2.SINIF ÖRGÜN

*/ 

char registerBul(char rjster);
bool registerMi(char ch);
char girilenKomut(char harf1,char harf2,char harf3);
void yazdir();
void hesapla(char operator, char register1, char register2, int sayi);
int desimalBinary(int r);

short AX=0,BX=0,CX=0,DX=0;
short RAM[256];   

int main(int argc, char *argv[]) {

	
    FILE *belge;
    char dosya_adi[20];
    char ch;
    int a=0;
	int s=0;
	char komutSatiri[20];
    
    puts("Dosya adini:--> kod.txt girisi yapiniz" );
    printf("****Girilen AX BX CX DX degerlerini giris yaptiktan sonra indentation kuralina gore devam ettiriniz..****");
    scanf("%s",dosya_adi);
   
    belge=fopen(dosya_adi,"r");
    
    if (belge == NULL)
    {
        printf("Dosya bulunamadý \nDosya yolunu duzeltiniz\n");
    }
    else
    {
	  
              while(fgets(komutSatiri, 15, belge) != NULL){
                printf("%s",komutSatiri);
                    
                char komut_Char = girilenKomut(komutSatiri[0],komutSatiri[1],komutSatiri[2]);
                    printf("%c\n",komut_Char);
				char resjisterChar= registerBul(komutSatiri[5]);
                    printf("%c\n",resjisterChar);
               
                  
                 if(registerMi(komutSatiri[8])){
                 	char resjister2Char= registerBul(komutSatiri[8]);
                 	printf("%c \n",resjister2Char);
				    hesapla(komut_Char,resjisterChar,resjister2Char,0);
	
	              }else if(komutSatiri[8]=='['){                     //KOMUTTAKÝ SAYININ TESPÝT EDÝLMESÝ
	                	int i=0,m;
                          int sayi;
                        	for(i=8;i<15;i++){
	                               if(isdigit(komutSatiri[i])){
                                      m=(komutSatiri[i]-'0');
                                      i=i+1;
                                 while(isdigit(komutSatiri[i])){
                                   m=m*10 + (komutSatiri[i]-'0');
                                          i++;
                                         }
                                 sayi=m;
                                     }
        
                                  }
                           printf("%d = Hemen Adresleme Degeri \n",sayi);
	                  hesapla(komut_Char,resjisterChar,'[', sayi);
	
	              }else {                                             //KOMUTTAKÝ SAYININ TESPÝT EDÝLMESÝ
			          	int i=0,m;
                          int sayi;
                        	for(i=8;i<15;i++){
	                               if(isdigit(komutSatiri[i])){
                                      m=(komutSatiri[i]-'0');
                                      i=i+1;
                                 while(isdigit(komutSatiri[i])){
                                   m=m*10 + (komutSatiri[i]-'0');
                                          i++;
                                         }
                                 sayi=m;
                                     }
        
                                  }
                           printf("%d = Hemen Adresleme Degeri \n",sayi);
					    hesapla(komut_Char,resjisterChar,'X', sayi);
	               } 
}
    }
      
     
    
    fclose(belge);
    yazdir();
   
	return 0;
}

// FONKSÝYON KISMI
char registerBul(char rjster) {
        char rj = 0;
        switch (rjster) {
            case 'A':                    
                rj = 'A'; break;
            case 'B':
                rj = 'B'; break;
            case 'C':
               rj = 'C'; break;
            case 'D': 
			   rj = 'D'; break;
    }
        return rj;
}
    
    
bool registerMi(char ch) 
{ 
	if (ch == 'A' || ch == 'B' || ch == 'C' || ch == 'D')
		return (true); 
	return (false); 
} 
    
char girilenKomut(char harf1,char harf2,char harf3) {
        char komutCharGonder = 0;
        if (harf1 == 'H') {                           //HRK Komutu
            komutCharGonder = '=';
        } else if (harf1 == 'T') {                    //TOP KOMUTU
            komutCharGonder = '+';
        } else if (harf1 == 'C' && harf2 == 'R') {    //CARP KOMUTU
             komutCharGonder = '*';
        } else if (harf1 == 'C' && harf3 == 'K') {    //CIKAR KOMUTU
            komutCharGonder = '-';
        } else if (harf1 == 'B') {                    //BOL KOMUTU
           komutCharGonder = '/';
        } else if (harf1 == 'V' && harf3 == ' ') {    //VE KOMUTU
            komutCharGonder = '&';
        } else if (harf1 == 'V' && harf3 == 'Y') {    //VEYA KOMUTU
            komutCharGonder = '|';
        } else if (harf1 == 'D') {                    //VEYA KOMUTU
              komutCharGonder = '!';
        }
     
	return komutCharGonder;
    }
     

void yazdir(){
  printf("***** CIKAN SONUC  ***** \n");
  printf("AX: (%d) ",AX);desimalBinary(AX);
  printf("BX: (%d) ",BX);desimalBinary(BX);
  printf("CX: (%d) ",CX);desimalBinary(CX);
  printf("DX: (%d) ",DX);desimalBinary(DX);
}


int desimalBinary(int r){

  int a[10],n,i;          
  n=r;
  for(i=0;n>0;i++)    
  {    
     a[i]=n%2;    
     n=n/2;    
  }     
 
  for(i=i-1;i>=0;i--)    
  {    
    printf("%d",a[i]);    
  }  
   printf("\n"); 
}



void hesapla(char operator, char register1, char register2, int sayi) {
        printf("Cikti \n");
  
        int reji2 = 0;
        switch (register2) {
            case 'A':
                reji2 = AX;
                break;
            case 'B':
                reji2 = BX;
                break;
            case 'C':
                reji2 = CX;
                break;
            case 'D':
                reji2 = DX;
                break;
        }

        if ('=' == (operator)) {
            switch (register1) {
                case 'A':
                    switch (register2) {
                        case 'X':                        //GÝRÝLEN SAYI DEÐERÝ
                            AX = sayi;                   // AX DEÐERÝNÝN SAYIYA GÝRÝÞÝ
                            break;
                        case '[':                        //TUTULAN BELLEK ADRESÝ
                            AX = RAM[sayi];
                            break;
                        default:
                            AX = reji2;
                            break;
                    }
                           
                    break;

                case 'B':
                    switch (register2) {
                        case 'X':                         //GÝRÝLEN SAYI DEÐERÝ
                            BX = sayi;                    //BX  DEÐERÝNÝN SAYIYA GÝRÝÞÝ
                            break;
                        case '[':                         //BELLEK ADRESÝ
                            BX = RAM[sayi];
                            break;
                        default: 
                            BX = reji2;
                            break;
                    }
                    break;
                case 'C':
                    switch (register2) {
                        case 'X':                         //GÝRÝLEN SAYI DEÐERÝ 
                            CX = sayi;					  //CX DEÐERÝNÝN SAYIYA GÝRÝÞÝ	
                            break;
                        case '[':                         //bBELLEK ADRESÝ
                            CX = RAM[sayi];
                            break;
                        default:
                            CX = reji2;
                            break;
                    }
                 break;
                case 'D':
                    switch (register2) {
                        case 'X':                         //GÝRÝLEN SAYI DEÐERÝ
                            DX = sayi;                    //DX DEÐERÝNÝN SAYIYA GÝRÝÞÝ
                            break;
                        case '[':                         //BELLEK ADRESÝ
                            DX = RAM[sayi];
                            break;
                        default:
                            DX = reji2;
                            break;
                    }
                    break;
            }
        } else if ('+' == (operator)) {   //TOPLAMA ÝÞLEMÝ GÝRÝÞÝ
            switch (register1) {
                case 'A':				  // A KISMI TOPLAMA ÝÞLEMÝ
                    switch (register2) {

                        case 'X':               
                            AX = AX + sayi;
                            break;
                        case '[':  
                            AX = AX + RAM[sayi];
                            break;
                        default:
                            AX = AX + reji2;

                            break;
                    }
                                         //("++ AX=" + AX + " Rejister2=" + reji2 + " Sayi=" + sayi);
                    break;
                case 'B':				//B KISMI TOPLAMA ÝÞLEMÝ 
                    switch (register2) {
                        case 'X': 
                            BX = BX + sayi;
                            break;
                        case '[':  
                            BX = BX + RAM[sayi];
                            break;
                        default:
                            BX = BX + reji2;

                            break;
                    }

                    break;
                case 'C':				//C KISMI TOPLAMA ÝÞLEMÝ
                    switch (register2) {
                        case 'X':  
                            CX = CX + sayi;
                            break;
                        case '[':  
                            CX = CX + RAM[sayi];
                            break;
                        default:
                            CX = CX + reji2;

                            break;
                    }
                  break;
                case 'D':			   // D KISMI TOPLAMA ÝÞLEMÝ
                    switch (register2) {
                        case 'X':  
                            DX = DX + sayi;
                            break;
                        case '[':  
                            DX = DX + RAM[sayi];
                            break;
                        default:
                            DX = DX + reji2;

                            break;
                    }
                    break;
            }

        } else if ('*' == (operator)) {  //ÇARPMA ÝÞLEMÝ GÝRÝÞÝ
            switch (register1) {
                case 'A':					//A KISMINDA ÇARPMA ÝÞLEMÝ
                    switch (register2) {
                        case 'X':  
                            AX = AX * sayi;
                            break;
                        case '[':  
                            AX = AX * RAM[sayi];
                            break;
                        default:
                            AX = AX * reji2;

                            break;
                    }

                    break;
                case 'B':					//B KISMINDA ÇARPMA ÝÞLEMÝ
                    switch (register2) {
                        case 'X':   
                            BX = BX * sayi;
                            break;
                        case '[':  
                            BX = BX * RAM[sayi];
                            break;
                        default:
                            BX = BX * reji2;

                            break;
                    }
                    break;
                case 'C':					//C KISMINDA ÇARPMA ÝÞLEMÝ
                    switch (register2) {
                        case 'X':   
                            CX = CX * sayi;
                            break;
                        case '[':  
                            CX = CX * RAM[sayi];
                            break;
                        default:
                            CX = CX * reji2;

                            break;
                    }
                  break;
                case 'D': 					//D KISMINDA ÇARPMA ÝÞLEMÝ
                    switch (register2) {
                        case 'X':   
                            DX = DX * sayi;
                            break;
                        case '[': 
                            DX = DX * RAM[sayi];
                            break;
                        default:
                            DX = DX * reji2;

                            break;
                    }
                    break;
            }

        } else if ('-' == (operator)) {	//ÇIKARMA ÝÞLEMÝ
            switch (register1) {
                case 'A':				// A KISMINDA ÇIKARMA ÝÞLEMÝ
                    switch (register2) {
                        case 'X':  
                            AX = AX - sayi;
                            break;
                        case '[':  
                            AX = AX - RAM[sayi];
                            break;
                        default:
                            AX = AX - reji2;

                            break;
                    }
                    break;
                case 'B':				// B KISMINDA ÇIKARMA ÝÞLEMÝ
                    switch (register2) {
                        case 'X':  
                            BX = BX - sayi;
                            break;
                        case '[':  
                            BX = BX - RAM[sayi];
                            break;
                        default:
                            BX = BX - reji2;

                            break;
                    }
                    break;
                case 'C':				//C KISMINDA ÇIKARMA ÝÞLEMÝ
                    switch (register2) {
                        case 'X':  
                            CX = CX - sayi;
                            break;
                        case '[':  
                            CX = CX - RAM[sayi];
                            break;
                        default:
                            CX = CX - reji2;

                            break;
                    }
                  break;
                case 'D':				// D KISMINDA ÇIKARMA ÝÞLEMÝ
                    switch (register2) {
                        case 'X':  
                            DX = DX - sayi;
                            break;
                        case '[':  
                            DX = DX - RAM[sayi];
                            break;
                        default:
                            DX = DX - reji2;

                            break;
                    }

                    break;
            }

        } else if ('/' == (operator)) {	//BÖLME ÝÞLEMÝ
            switch (register1) {
                case 'A':					//A KISMINDA BÖLME ÝÞLEMÝ
                    switch (register2) {
                        case 'X':  
                            AX = AX / sayi;
                            break;
                        case '[':  
                            AX = AX / RAM[sayi];
                            break;
                        default:
                            AX = AX / reji2;

                            break;
                    }

                    break;
                case 'B':					//B KISMINDA BÖLME ÝÞLEMÝ
                    switch (register2) {
                        case 'X':  
                            BX = BX / sayi;
                            break;
                        case '[':  
                            BX = BX / RAM[sayi];
                            break;
                        default:
                            BX = BX / reji2;

                            break;
                    }
                    break;
                case 'C':					//C KISMINDA BÖLME ÝÞLEMÝ
                    switch (register2) {
                        case 'X':  
                            CX = CX / sayi;
                            break;
                        case '[':  
                            CX = CX / RAM[sayi];
                            break;
                        default:
                            CX = CX / reji2;

                            break;
                    }
					break;
                case 'D':				   //D KISMINDA BÖLME ÝÞLEMÝ
                    switch (register2) {
                        case 'X':  
                            DX = DX / sayi;
                            break;
                        case '[':  
                            DX = DX / RAM[sayi];
                            break;
                        default:
                            DX = DX / reji2;

                            break;
                    }

                    break;
            }

                   
        } else if ('&' == (operator)) { // VE KOMUTU
            switch (register1) {
                case 'A':
                    switch (register2) {
                        case 'X':  
                            AX = AX & sayi;
                            break;
                        case '[':  
                            AX = AX & RAM[sayi];
                            break;
                        default:
                            AX = AX & reji2;
                            break;
                    }
                    break;
                case 'B':
                    switch (register2) {
                        case 'X':  
                            BX = BX & sayi;
                            break;
                        case '[':  
                            BX =BX & RAM[sayi];
                            break;
                        default:
                            BX = BX & reji2;

                            break;
                    }

                    break;
                case 'C':
                    switch (register2) {
                        case 'X':   
                            CX = CX &sayi;
                            break;
                        case '[':  
                            CX = CX & RAM[sayi];
                            break;
                        default:
                            CX = CX & reji2;

                            break;
                    }
                    break;
                case 'D':
                    switch (register2) {
                        case 'X':  
                            DX = DX & sayi;
                            break;
                        case '[':  
                            DX = DX & RAM[sayi];
                            break;
                        default:
                            DX = DX & reji2;

                            break;
                    }

                    break;
            }

        } else if ('|' == (operator)) { // VEYA KOMUTU
            switch (register1) {
                case 'A':
                    switch (register2) {
                        case 'X': 
                            AX = AX | sayi;
                            break;
                        case '[':  
                            AX = AX | RAM[sayi];
                            break;
                        default:
                            AX = AX | reji2;

                            break;
                    }

                    break;
                case 'B':
                    switch (register2) {
                        case 'X':   
                            BX = BX | sayi;
                            break;
                        case '[':  
                            BX = BX | RAM[sayi];
                            break;
                        default:
                            BX = BX | reji2;

                            break;
                    }
                    break;
                case 'C':
                    switch (register2) {
                        case 'X':  
                            CX = CX |sayi;
                            break;
                        case '[':  
                            CX = CX | RAM[sayi];
                            break;
                        default:
                            CX = CX | reji2;

                            break;
                    }
               break;
                case 'D':
                    switch (register2) {
                        case 'X':  
                            DX = DX |sayi;
                            break;
                        case '[':  
                            DX = DX |RAM[sayi];
                            break;
                        default:
                            DX = DX |reji2;
                            break;
                    }

                    break;
            }

        } else if ('!' == (operator)) { // DEÐÝLÝ KOMUTU
            switch (register1) {
                case 'A':
                    switch (register2) {
                        case 'X':  
                            AX = 256+~sayi;
                            break;
                        case '[': 
                            AX = 256+~RAM[sayi];
                            break;
                        default:
                            AX = 256+~reji2;
                            break;
                    }

                    break;
                case 'B':
                    switch (register2) {
                        case 'X':  
                            BX = 256+~sayi;
                            break;
                        case '[':  
                            BX = 256+~RAM[sayi];
                            break;
                        default:
                            BX = 256+~reji2;

                            break;
                    }
                    break;
                case 'C':
                    switch (register2) {
                        case 'X':  
                            CX = 256+~sayi;
                            break;
                        case '[':  
                            CX = 256+~RAM[sayi];
                            break;
                        default:
                            CX = 256+~reji2;

                            break;
                    }
                    break;
                case 'D':
                    switch (register2) {
                        case 'X':  
                            DX = 256+~sayi;
                            break;
                        case '[':  
                            DX = 256+~RAM[sayi];
                            break;
                        default:
                            DX = 256+~reji2;

                            break;
                    }

                    break;
            }

        }
        printf("AX=%d BX=%d CX=%d DX=%d \n",AX,BX,CX,DX,"\n");
    }



 

 
