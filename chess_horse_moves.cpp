#include <stdio.h>
#include <stdlib.h>
void s_tahtasi_esit(int tahta_birleme[10][10]){    // burada 10*10 matrisin elemanlar�n� 1 e e�itleyece�iz elle yapmak icin 100 de�er girmek veya 10 tane kume yazmak s�k�nt� olur.
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		tahta_birleme[i][j]=1;
	}
}
void at_hareket(int x,int y,int hareket[10][10])  // bu fonksiyon at�n gidebilecegi yerleri bulur bize... // Burada 3 parametre se�memizin sebebi ise girilen degerlerler i�lem yapt�g�m�zdand�r.
{		hareket[2+x][2+y]=0;						// bir L �eklinde yani 3 kare atlayarak gider.Biz ise bunu 2 ve 1 say�lari ile bulucaz 
		hareket[2+x-2][2+y+1]=9;					// 2 ve 1 say�lar�n�n farkl� kombinasyou bize at�n hareketini verecektir. Dizi 10 10 se�memmiz ise 
		hareket[2+x-2][2+y-1]=9;					// Dizinin ta�mas�n� engellemek icin kullan�cag�z. yani at�n konumu k��elere gelince bu i�len ile program sa�malamayacak.
		hareket[2+x+2][2+y+1]=9;					 //Alakas�z yerleri g�stermeyecek. yoksa at�n gitmedigi yerleri g�sterebilir bize.
		hareket[2+x+2][2+y-1]=9;
		hareket[2+x+1][2+y+2]=9;	
		hareket[2+x+1][2+y-2]=9;
		hareket[2+x-1][2+y+2]=9;
		hareket[2+x-1][2+y-2]=9;
}
void tahta_yazdir(int tahta[10][10]){    // bu fonksiyon ile tahtayi ekrana bast�racag�z.
	int i,j,k;
	for(i=1;i<=8;i++)
	{
		printf(" %4d",i);
	}
	printf("\n");
	for(i=2;i<=9;i++)
	{	printf("%d",i-1); 
		for(j=2;j<=9;j++)
		{
			printf("%4d ",tahta[i][j]);
			
			
		}
		printf("\n"); 
	}
}
void tahta_sifirla(int dizi1[10][10])  // Bu fonksiyon yazmam�z�n sebebi at�n bir sonraki hamle ile  konumunun belirlendi�inde,
{	int i,j,k; 						  // eski konumunu silmek icin kullan�yoruz yani 0 da iken tekrar 1 e getirecegiz...
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		dizi1[i][j]=1;
	}
		
		}	

int main(int argc, char *argv[]) {
	
	int i,j,k,satir,sutun;
	int s_tahtasi[10][10];				// Normalde satran� tahtasi 8x8 ama biz burda dizinin ta�mas�n� engellemek icin 10x10kullan�cag�z. 
										// yani at�n konumu k��elere gelince bu i�len ile program sa�malamayacak.
										// Alakas�z yerleri g�stermeyecek. yoksa at�n gitmedigi yerleri g�sterebilir bize.
										// Burada satran� tahtas�n� 1 lerle g�sterecegiz at�n konumunu ise 0 ile g�sterecegiz gidebilecegi noktalari ise 9 ile g�sterecegiz.
										// bu rakamlar� se�memin �zel bir nedeni yok sadece daha rahat alg�lanabilsin diye sectim.
	

	s_tahtasi_esit(s_tahtasi);

	yeni_konum_iste:
	tahta_yazdir(s_tahtasi);
	printf("\nAtin baslangic konumunu giriniz..!\n"); 
	printf("\nSatir numarasini giriniz: ");
	scanf("%d",&satir);
	satir=satir-1;    /// girilen degerden -1 c�karmam�n nedeni C de dizilerin indisi 0 dan ba�lamas�ndan kaynaklan�yor bunu ortadan kald�rmak icin b�yle bir strateji uygulad�m.
	printf("Sutun numarasini giriniz: ");
	scanf("%d",&sutun); sutun=sutun-1;
		if(satir+1>8 || sutun+1>8 || sutun+1<=0 || satir+1<=0 )
		{
			printf("\nLutfen atin konumunu satranc tahtasina uygun olarak giriniz..!\n");
			goto yeni_konum_iste;
		}
		else ;
	
	int x=0;
	s_tahtasi[2+satir][2+sutun]=x; // burada at�n konumunu girdik �imdi at burdan nerelere gidebilir bunun yerlerini bulucaz.
	printf("\nAtin baslangic konumu asagida 0 ile gosterilmistir...\n");
	tahta_yazdir(s_tahtasi); //at�n konumunu girdikten sonra tekrardan at�n yerini g�rmek i�in at� 0 ile g�sterice�iz gidebilece�i yerleri yapaca��z �imdi.
					//at max 8 yere gidebilir ...	
	
		

	
	    printf("\nAtin baslangic konumundan bir sonraki gidebilecegi muhtemel konum asaigda 9 ile gosterilmistir.\n ");      
	at_hareket(satir,sutun,s_tahtasi); 

		printf("\n");

			tahta_yazdir(s_tahtasi);
			while(1){ 																		//Bu koda while eklemememin sebebi ise biraz daha kodun e�lenceli olmasi icin.
			printf("\nEger programdan cikmak isterseniz 0 dan kucuk bir deger giriniz!!!\n");
			printf("\nAtin harekatinin devami icin yeni bir konum seciniz!");
			printf("\nSatir numarasini giriniz: ");
			scanf("%d",&satir);
			satir=satir-1;
			printf("\nSutun numarasini giriniz: ");
			scanf("%d",&sutun);
			sutun=sutun-1;
			
			if(satir<0||sutun<0) // burada program� kapatmak istersek bu negatif bir deger girerek programdan ��kabiliriz.
			{
				break;
			}
			if(s_tahtasi[2+satir][2+sutun]!=9)  // bu kod ise eger kullan�c� at�n gidecegi m�mk�n yerlere gitmedigi zaman kullan�c�y� uyaracakt�r.
			{
				printf("\nLutfen Atin gidebilecegi konumlardan birini seciniz..!\n");
				tahta_yazdir(s_tahtasi);
			}
			else{									// eger kullan�c� uygun konumu girerse program 91. sat�rdan tekrar icra edilecektir.
					tahta_sifirla(s_tahtasi);
					at_hareket(satir,sutun,s_tahtasi);
					tahta_yazdir(s_tahtasi);
			}
			}	
			
			
			
	return 0;
}
