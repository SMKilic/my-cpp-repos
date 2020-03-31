#include <stdio.h>
#include <stdlib.h>
void s_tahtasi_esit(int tahta_birleme[10][10]){    // burada 10*10 matrisin elemanlarýný 1 e eþitleyeceðiz elle yapmak icin 100 deðer girmek veya 10 tane kume yazmak sýkýntý olur.
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		tahta_birleme[i][j]=1;
	}
}
void at_hareket(int x,int y,int hareket[10][10])  // bu fonksiyon atýn gidebilecegi yerleri bulur bize... // Burada 3 parametre seçmemizin sebebi ise girilen degerlerler iþlem yaptýgýmýzdandýr.
{		hareket[2+x][2+y]=0;						// bir L þeklinde yani 3 kare atlayarak gider.Biz ise bunu 2 ve 1 sayýlari ile bulucaz 
		hareket[2+x-2][2+y+1]=9;					// 2 ve 1 sayýlarýnýn farklý kombinasyou bize atýn hareketini verecektir. Dizi 10 10 seçmemmiz ise 
		hareket[2+x-2][2+y-1]=9;					// Dizinin taþmasýný engellemek icin kullanýcagýz. yani atýn konumu köþelere gelince bu iþlen ile program saçmalamayacak.
		hareket[2+x+2][2+y+1]=9;					 //Alakasýz yerleri göstermeyecek. yoksa atýn gitmedigi yerleri gösterebilir bize.
		hareket[2+x+2][2+y-1]=9;
		hareket[2+x+1][2+y+2]=9;	
		hareket[2+x+1][2+y-2]=9;
		hareket[2+x-1][2+y+2]=9;
		hareket[2+x-1][2+y-2]=9;
}
void tahta_yazdir(int tahta[10][10]){    // bu fonksiyon ile tahtayi ekrana bastýracagýz.
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
void tahta_sifirla(int dizi1[10][10])  // Bu fonksiyon yazmamýzýn sebebi atýn bir sonraki hamle ile  konumunun belirlendiðinde,
{	int i,j,k; 						  // eski konumunu silmek icin kullanýyoruz yani 0 da iken tekrar 1 e getirecegiz...
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		dizi1[i][j]=1;
	}
		
		}	

int main(int argc, char *argv[]) {
	
	int i,j,k,satir,sutun;
	int s_tahtasi[10][10];				// Normalde satranç tahtasi 8x8 ama biz burda dizinin taþmasýný engellemek icin 10x10kullanýcagýz. 
										// yani atýn konumu köþelere gelince bu iþlen ile program saçmalamayacak.
										// Alakasýz yerleri göstermeyecek. yoksa atýn gitmedigi yerleri gösterebilir bize.
										// Burada satranç tahtasýný 1 lerle gösterecegiz atýn konumunu ise 0 ile gösterecegiz gidebilecegi noktalari ise 9 ile gösterecegiz.
										// bu rakamlarý seçmemin özel bir nedeni yok sadece daha rahat algýlanabilsin diye sectim.
	

	s_tahtasi_esit(s_tahtasi);

	yeni_konum_iste:
	tahta_yazdir(s_tahtasi);
	printf("\nAtin baslangic konumunu giriniz..!\n"); 
	printf("\nSatir numarasini giriniz: ");
	scanf("%d",&satir);
	satir=satir-1;    /// girilen degerden -1 cýkarmamýn nedeni C de dizilerin indisi 0 dan baþlamasýndan kaynaklanýyor bunu ortadan kaldýrmak icin böyle bir strateji uyguladým.
	printf("Sutun numarasini giriniz: ");
	scanf("%d",&sutun); sutun=sutun-1;
		if(satir+1>8 || sutun+1>8 || sutun+1<=0 || satir+1<=0 )
		{
			printf("\nLutfen atin konumunu satranc tahtasina uygun olarak giriniz..!\n");
			goto yeni_konum_iste;
		}
		else ;
	
	int x=0;
	s_tahtasi[2+satir][2+sutun]=x; // burada atýn konumunu girdik þimdi at burdan nerelere gidebilir bunun yerlerini bulucaz.
	printf("\nAtin baslangic konumu asagida 0 ile gosterilmistir...\n");
	tahta_yazdir(s_tahtasi); //atýn konumunu girdikten sonra tekrardan atýn yerini görmek için atý 0 ile göstericeðiz gidebileceði yerleri yapacaðýz þimdi.
					//at max 8 yere gidebilir ...	
	
		

	
	    printf("\nAtin baslangic konumundan bir sonraki gidebilecegi muhtemel konum asaigda 9 ile gosterilmistir.\n ");      
	at_hareket(satir,sutun,s_tahtasi); 

		printf("\n");

			tahta_yazdir(s_tahtasi);
			while(1){ 																		//Bu koda while eklemememin sebebi ise biraz daha kodun eðlenceli olmasi icin.
			printf("\nEger programdan cikmak isterseniz 0 dan kucuk bir deger giriniz!!!\n");
			printf("\nAtin harekatinin devami icin yeni bir konum seciniz!");
			printf("\nSatir numarasini giriniz: ");
			scanf("%d",&satir);
			satir=satir-1;
			printf("\nSutun numarasini giriniz: ");
			scanf("%d",&sutun);
			sutun=sutun-1;
			
			if(satir<0||sutun<0) // burada programý kapatmak istersek bu negatif bir deger girerek programdan çýkabiliriz.
			{
				break;
			}
			if(s_tahtasi[2+satir][2+sutun]!=9)  // bu kod ise eger kullanýcý atýn gidecegi mümkün yerlere gitmedigi zaman kullanýcýyý uyaracaktýr.
			{
				printf("\nLutfen Atin gidebilecegi konumlardan birini seciniz..!\n");
				tahta_yazdir(s_tahtasi);
			}
			else{									// eger kullanýcý uygun konumu girerse program 91. satýrdan tekrar icra edilecektir.
					tahta_sifirla(s_tahtasi);
					at_hareket(satir,sutun,s_tahtasi);
					tahta_yazdir(s_tahtasi);
			}
			}	
			
			
			
	return 0;
}
