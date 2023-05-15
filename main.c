#include <stdio.h>
#include <stdlib.h>

//Kuyruk dügüm yapisi
struct dugum { //dügüm=veri+bir sonraki dügümü isaret eden isaretci
    int veri;//dugum yapisinin bir tam sayi üyesi
    struct dugum* ileri; //dugum yapisinin bir üyesi ve bir sonraki dügümü isaret etmek icin kullanilan bir isaretci
};

struct dugum* kuyruk_basi = 0 ; //struct dugum yapisiyla tanimlanan kuyruk_basi isaretcisi bir dügümü isaret etmez
struct dugum* kuyruk_sonu = 0 ; //struct dugum yapisiyla tanimlanan kuyruk_sonu isaretcisi bir dügümü isaret etmez

//Kuyruga eleman ekleme
void enqueue(int yeniveri) {
    struct dugum* yenidugum = (struct dugum*)malloc(sizeof(struct dugum));
	/*void türünde fonksiyon oldugu icin tür korunumunu saglamak
    adina malloc önüne (struct dugum*) yapisini ekledik.*/
    //malloc fonksiyonuyla dinamik bellek tahsis ettik
    //sizeof fonksiyonuyla dugum yapisinin bellekte kapladigi alani aldik.
    // yenidugum isaretcisi yeni olusturulan dügümün baslangic adresini tutar
    /*bu ifade yeni bir dügüm olusturmak icin bellekte gerekli alani ayirir ve yenidügüm isaretcisi bu dügümü
    isaret eder */
    
    yenidugum->veri = yeniveri;//yenidugum isaretcisiyle erisilen dügümün 'veri' uyesine yeniveri degerini atar
    yenidugum->ileri = 0 ; //yenidugum isaretcisiyle erisilen dügümün 'ileri' isaretci uyesine 0 atar

    if (kuyruk_sonu == 0) { // kuyruksonu isaretcisi 0'sa bu if icine gir
    //kuyruk bos mu dolu mu kontrolu
        kuyruk_basi = kuyruk_sonu = yenidugum; //yenidugum ,kuyrugun tek dügümü oldugunu ve hem basi hem sonu oldugunu belirtir
    } else { //kuyruk bos degilse
        kuyruk_sonu->ileri = yenidugum; //kuyruk_sonu isaretcisiyle erisilen ileri isaretcisine yenidugum isaretcisi atanir
        kuyruk_sonu = yenidugum; //kuyruk_sonu isaretcisine yeni dugum isaretcisi atanir
        //bu kuyruk_sonu isaretcisinin yeni eklenen dugumu isaret ettigi manasina gelir
    }

    printf("%d kuyruga eklendi.\n", yeniveri); //eklenen dugumun verisi yazdirilir
}

//Kuyruktan eleman silme
void dequeue() {
    if (kuyruk_basi == 0) { //kuyruk_basi 0'sa bu if'in icine gir
        printf("Kuyruk bos.\n");
        return;//fonksiyon sonlanir cunku kuyruk bossa eleman silemeyiz
    }
    
    /*cikarilacak olan dugum gecici olarak gecici_isaretci de saklanir.
	 Ardindan kuyruk_basi isaretcisi cikarilan dugumun bir sonraki
	 dugume isaret etmesi icin gunccelenir ve kuyruktan bir dugum cikartilir*/
    struct dugum* gecici_isaretci = kuyruk_basi; //struct dugum veri yapisiyla gecici_isaretci tanimlanir ve kuyruk_basi'na atanir.
      kuyruk_basi = kuyruk_basi->ileri; /*kuyruk_basi isaretcisiyle erisilen ileri isaretcisi , kuyruk_basi isaretcisine atanir.
   Bu islem kuyruktan bir dugumun cikarildigi anlamina gelir*/
   
   //burada ikinci kez kuyruk_basi isaretcisinin isaret ettigi dugumun bos olup olmadigini kontrol etmemizin sebebi
   //kuyrukta ikinci bir dugum var mi yok mu anlamak icindir 
    if (kuyruk_basi == 0) { //bu islem kuyrugun tamamen bos oldugu durumu kontrol etmek icin kullandik
        kuyruk_sonu = 0; //kuyruk sonu isaretcisinin de 0 'a atanmis olmasi kuyrugun basinin da bos oldugu manasina gelir.
    }

    printf("%d kuyruktan cikarildi.\n", gecici_isaretci->veri);//gecici_isaretci'sinin gosterdigi dugumun verisini yazdiririz.
    free(gecici_isaretci);//gecici_isaretci ile gosterilen dugumun bellegi serbest birakilir
}

//Kuyrugu görüntüleme
void display() {
    if (kuyruk_basi == 0) {//kuyruk_Basi isaretcisi bir sey isaret etmiyorsa
        printf("Kuyruk bos.\n");
        return; //fonksiyon sonlanir
    }

    struct dugum* dolasma = kuyruk_basi;// struct dugum veri yapisiyla tanimlanan dolasma isaretcisi,kuyruk_basi isaretcisine atanir.
//bu sayede kuyruk basi isaretcisinin isaret ettigi dugum ile dolasma isaretcisinin isaret ettigi dugum aynidir.
    printf("Kuyruk: ");
    while (dolasma != 0) { //dolasma isaretcisinin isaret ettigi bir dugum yokken dongu devam eder
        printf("%d ", dolasma->veri); //dolasma isaretcisiyle erisilen dugumun veri uyesi ekrana yazdirilir
        dolasma = dolasma->ileri; // dolasma isaretcisine, dolasma isaretcisiyle erisilen dugumun ileri isaretci uyesi atanir.
    }//bu islem mevcut dugumun bir sonraki dugumu isaret etmesini saglar
    printf("\n");
}

int main() {
	
	
	printf("Hazirlayan: Eda Nur Ergin-1220505032");
	printf("\n\n");
	
	int secim;
	int verim;
	
	printf("Kuyruklarin Baglantili Liste Uygulamasi\n");
	printf("1.Ekleme \n");
	printf("2.Silme \n");
	printf("3.Goruntuleme \n");
	printf("4.Cikis \n\n");
	
   while(1)//sonsuz donguye alarak sistemin bir akis halinde olmasini sagladik
  { 
	
	printf("Lutfen istediginiz secenegin numarasini giriniz:  ");
	scanf("%d",&secim);
	
	switch(secim)
	{
		case 1 :
			printf("Kuyruga Eleman Ekleme Alani\n");
			printf("Eklemek istediginz veriyi girin : \n");
			scanf("%d",&verim);//kullanicidan eklemek istedigi veriyi aldik.
			enqueue(verim);//kuyruga eleman ekleme fonksiyonun cagirdik
			break;
		
		case 2 :
			printf("Kuyruga Eleman Silme Alani\n");
			dequeue() ; //kuyruktan eleman silme fonkisyonunu cagirdik
			break ;
			
		case 3 :
			printf("Kuyruga Elemanlarini Goruntuleme Alani\n");
			display(); //kuyrugun elemanlariini goruntuleyen fonksiyonu cagirdik
			break;
			
	    case 4 :
	    	printf("Cikis Ekrani \n");
	    	printf("Kuyruk sisteminden ciktiniz");
	    	if(secim==4)
			return 0; 
			
	    default :
	    	printf("Yanlis secenek girisi yaptiniz. Tekrar Deneyiniz !! \n");		
		
	}
  } 
    return 0;
}

