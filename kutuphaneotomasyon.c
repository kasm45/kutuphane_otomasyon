#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 
#include <ctype.h>

typedef struct
{
    
    char kitapAdi [ 100 ];
    char yazarAdi [ 100 ];
    int sayfaSayisi;
    char ISBNno[ 15 ];
    bool KitapDurum;

} Kitaplar;

typedef struct 
{
    
    char kullaniciAdi[ 50 ];
    char kullaniciSoyadi[ 50 ];
    char email[ 20 ];
    char telefon[ 11 ];
    char sifre[ 20 ];
    char AlinanKitapAdi[ 100 ];

} Kullanici;

void AnaMenu();
void KitapEkle( Kitaplar kitaplar2[], int *index );
void KitapListele( Kitaplar kitaplar2[], int *index );
void KitapAra( Kitaplar kitaplar2[], int *index );
void KitapSil( Kitaplar kitaplar2[], int *index );
void KitapGuncelle( Kitaplar kitaplar2[], int *index );
void KitapOduncAl( Kitaplar kitaplar2[], Kullanici kullanici2[], int *kitaplarIndex, int *kullaniciIndex );
void KitapIadeEt( Kitaplar kitaplar2[], Kullanici kullanici2[], int *kitaplarIndex, int *kullaniciIndex );

void KullaniciAnaMenu();
void KullaniciEkle( Kullanici kullanici2[], int *index );
int KullaniciKontrol( Kullanici kullanici2[], int *index );

int main()
{
    int secim, index = 0, depo, kullaniciSecim, kullaniciIndex = 0, kapasite = 100;
    bool kontrol;

    Kitaplar *kitaplar1 = malloc( kapasite * sizeof(Kitaplar));
    Kullanici *kullanici1 = malloc( 100 * sizeof( Kullanici ) );

    KullaniciAnaMenu();
    scanf("%d", &kullaniciSecim );

    switch ( kullaniciSecim )
    {
        case 1:

            girisTekrarDene: 

            kontrol = KullaniciKontrol( kullanici1, &kullaniciIndex );

            if ( kontrol == 1 )
            {
                goto kitapSistemi;
            }
            else
            {
                int dene;
                printf("Bir Daha Giris Yapmak Icin 1, Cikis Yapmak Istiyorsaniz 2 Rakamina Basiniz\n");
                printf("Seciminiz: ");
                scanf("%d", &dene );

                if ( dene == 1 )
                {
                    goto girisTekrarDene;
                }
                else
                { 
                    goto cikis;
                }
            }

            break;
        case 2:

            goto cikis;

            break;
        case 3:

            kullaniciEkle:
            printf("\n");
            getchar();
            KullaniciEkle( kullanici1, &kullaniciIndex );

            
            int gidilecekYer;

            printf("Eger Yeni Bir Kullanici Eklemek Istiyorsaniz 1 Rakamina Basiniz.\n");
            printf("Eger Kitap Sistemine Gitmek Istiyorsaniz 2 Rakamina Basiniz.\n");
            printf("Seciminiz: ");
            scanf( "%d", &gidilecekYer );

            if ( gidilecekYer == 1 )
            {
                goto kullaniciEkle;
            }
            else
            {
                kontrol = KullaniciKontrol( kullanici1, &kullaniciIndex );
                if ( kontrol == 1 )
                {
                    goto kitapSistemi;
                }
                else
                {
                    goto cikis;
                }
            }
            

            break;
        case 4:

            goto cikis;

            break;
        default:
                
            printf("Lutfen Gecerli Bir Deger Giriniz.\n");

            break;
    }


    kitapSistemi:

    AnaMenu();
    scanf("%d", &secim );
    getchar();

    while( secim != 8 )
    {

            switch ( secim )
            {   
                case 1:

                    printf("\n");
                    KitapEkle( kitaplar1, &index );

                    break;
                case 2:

                    KitapListele( kitaplar1, &index );

                    break;
                case 3:

                    KitapAra( kitaplar1, &index );

                    break;
                case 4:

                    KitapListele( kitaplar1, &index );
                    KitapSil( kitaplar1, &index );
                    printf("--- Kutuphane Otomasyon Sistemimizden Silmek Istediginiz Kitap Cikarildiktan Sonraki Kitap Listemiz ---\n");
                    KitapListele( kitaplar1, &index );

                    break;
                case 5:

                    KitapListele( kitaplar1, &index );
                    KitapGuncelle( kitaplar1, &index );
                    KitapListele( kitaplar1, &index );

                    break;
                case 6:

                    KitapListele( kitaplar1, &index );
                    KitapOduncAl( kitaplar1, kullanici1, &index, &kullaniciIndex );

                    break;
                case 7:

                    KitapListele( kitaplar1, &index );
                    KitapIadeEt( kitaplar1, kullanici1, &index, &kullaniciIndex );

                    break;
                default:
                    printf("Lutfen Giris Degeri Olan Bir Giris Degeri Giriniz.\n");
                    break;

            }

        printf("\n\n");
        AnaMenu();
        scanf("%d", &secim );
        getchar();

    }

    cikis:

    printf("\nKutuphane Otomasyon Sistemimizi Kullandiginiz Icin Tesekkur Ederiz. Ihtiyaciniz Oldugunda Yine Uygulamamizi Kullanmaniz Icin Bekleriz...");

    free(kitaplar1);
    free(kullanici1);
    
    return 0;
}

void KullaniciAnaMenu()
{
    printf("\n--- Merhabalar, Kutuphane Otomasyon Sistemimize Hosgeldiniz ---\n\n");
    printf("Eger Kutuphanemizin Otomasyon Sisteminde Aktif Uyeliginiz Varsa ve Giris Yapmak Istiyorsaniz 1 Rakamina Basiniz. \n");
    printf("Eger Kutuphanemizin Otomasyon Sisteminde Aktif Uyeliginiz Varsa ve Giris Yapmak Istemiyorsaniz 2 Rakamina Basiniz. \n");
    printf("Eger Kutuphanemizin Otomasyon Sisteminde Aktif Uyeliginiz Yoksa ve Giris Yapmak Istiyorsaniz Kayit Olmak Icin 3 Rakamina Basiniz. \n");
    printf("Eger Kutuphanemizin Otomasyon Sisteminde Aktif Uyeliginiz Yoksa ve Giris Yapmak Istemiyosaniz 4 Rakamina Basiniz. \n");
    printf("Seciminiz: ");

}

void KullaniciEkle( Kullanici kullanici2[], int *index )
{
    printf("Kutuphane Otomasyon Sistemimize Uye Olmak Icin Adinizi Giriniz: ");
    scanf("%[^\n]", kullanici2[ *index ].kullaniciAdi );
    getchar();

    printf("Kutuphane Otomasyon Sistemimize Uye Olmak Icin Soyadinizi Giriniz: ");
    scanf("%[^\n]", kullanici2[ *index ].kullaniciSoyadi );
    getchar();

    printf("Kutuphane Otomasyon Sistemimize Uye Olmak Icin E Mailinizi Giriniz: ");
    scanf("%[^\n]", kullanici2[ *index ].email );
    getchar();

    printf("Kutuphane Otomasyon Sistemimize Uye Olmak Icin Telefon Numaranizi Giriniz: ");
    scanf("%[^\n]", kullanici2[ *index ].telefon );
    getchar();

    printf("Kutuphane Otomasyon Sistemimize Uye Olmak Icin Bir Sifre Belirleyiniz: ");
    scanf("%[^\n]", kullanici2[ *index ].sifre );
    getchar();

    printf("Basari Ile Kutuphane Otomasyonumuza Kaydoldunuz, Tebrikler...\n\n");

    ( *index )++;
}

int KullaniciKontrol( Kullanici kullanici2[], int *index )
{
    char kullaniciAdi[ 50 ], sifre[ 20 ];
    
    getchar();
    printf("\nGiris Yapmak Icin Kullanici Adinizi Giriniz: ");
    scanf("%[^\n]", kullaniciAdi );
    getchar();
    
    printf("Giris Yapmak Icin Sifrenizi Giriniz: ");
    scanf("%[^\n]", sifre );

    bool kontrol = 0;

    for ( int i = 0; i < ( *index ); i++ )
    {
        if ( ( strcmp( kullanici2[ i ].kullaniciAdi, kullaniciAdi ) == 0 ) && ( strcmp( kullanici2[ i ].sifre, sifre ) == 0 ) )
        {
            kontrol = 1;
            break;
        }
        else
        {
            kontrol = 0;
        }
    }

    if( kontrol == 1 )
    {
        printf("Girdiginiz Kullanici Adi ve Sifre Dogrudur.\n");
    }
    else
    {
        printf("Kullanici Bulunamadi. Girdiginiz Kullanici Adi veya Sifre Yanlistir\n");
    }

    return kontrol;
}

void AnaMenu()
{
    
    printf("\n--- Kutuphane Kitap Menusu ---\n");
    printf("Kutuphanemize Kitap Eklemek Icin 1 Rakamina Basiniz\n");
    printf("Kutuphanemize Kitap Listelemek Icin 2 Rakamina Basiniz\n");
    printf("Kutuphanemize Kitap Aramak Icin 3 Rakamina Basiniz\n");
    printf("Kutuphanemize Kitap Silmek Icin 4 Rakamina Basiniz\n");
    printf("Kutuphanemize Kitap Verilerini Guncellemek Icin 5 Rakamina Basiniz\n");
    printf("Kutuphanemizden Odunc Kitap Almak Icin 6 Rakamina Basiniz\n");
    printf("Kutuphanemizden Alinan Odunc Kitabi Iade Etmek Icin 7 Rakamina Basiniz\n");
    printf("Kutuphane Otomasyon Sistemimizden Cikis Yapmak Icin 8 Rakamina Basiniz\n");
    printf("Seciminiz: ");

}

void KitapEkle( Kitaplar kitaplar2[], int *index )
{
    
    printf("Kutuphanemize Eklemek Istediginiz Kitabin Adini Giriniz: ");
    scanf("%[^\n]", kitaplar2[ *index ].kitapAdi);
    getchar();

    printf("Kutuphanemize Eklemek Istediginiz Kitabin Yazarinin Adini Giriniz: ");
    scanf("%[^\n]", kitaplar2[ *index ].yazarAdi);
    getchar();

    printf("Kutuphanemize Eklemek Istediginiz Kitabin Sayfa Sayisini Giriniz: ");
    scanf("%d", &kitaplar2[ *index ].sayfaSayisi);
    getchar();

    printf("Kutuphanemize Eklemek Istediginiz Kitabin ISBN No 'sunu Giriniz: ");
    scanf("%[^\n]", kitaplar2[ *index ].ISBNno );

    kitaplar2[ *index ].KitapDurum = 0;

    printf("Verilerini Girdiginiz Kitabiniz Kutuphanemize Basarili Bir Sekilde Eklendi, Tebrikler...\n");

    ( *index ) += 1;
}

void KitapListele( Kitaplar kitaplar2[], int *index )
{
    printf("\n");

    if ( ( *index ) == 0 )
    {
        printf("Kutuphane Otomasyon Sistemimize Girilmis Kitap Bulunmamaktadir.\n");
    }
    else
    {
        for( int i = 0; i < ( *index ); i++ )
        {
            printf("Kitap - %d -\n", ( i + 1 ) );
            printf("Kitabin Adi: %s\n", kitaplar2[i].kitapAdi );
            printf("Kitabin Yazari: %s\n", kitaplar2[i].yazarAdi );
            printf("Kitabin Sayfa Sayisi: %d\n", kitaplar2[i].sayfaSayisi );
            printf("Kitabin ISBN No 'su: %s\n", kitaplar2[i].ISBNno );
            
            if ( kitaplar2[ i ].KitapDurum == 1 )
            {
                printf("Kitabin Durumu: Odunc Alindi...\n");
            }
            else if ( kitaplar2[ i ].KitapDurum == 0 )
            {
                printf("Kitabin Durumu: Odunc Verilebilinir...\n");
            }

            printf("\n");
        }
    }
}

void KitapAra( Kitaplar kitaplar2[], int *index )
{
    char kitapAdi[ 100 ];
    bool kontrol = 0;
    printf("Aradiginiz Kitabin Ismini Giriniz: ");
    scanf("%[^\n]", kitapAdi );

    for ( int i = 0; i < ( *index ); i++ )
    {

        if ( ( strcmp( kitapAdi, kitaplar2[ i ].kitapAdi ) ) == 0 )
        {
            
            printf("\n--- Aradiginiz Kitap ---\n");
            printf("Kitabin Adi: %s\n", kitaplar2[i].kitapAdi );
            printf("Kitabin Yazari: %s\n", kitaplar2[i].yazarAdi );
            printf("Kitabin Sayfa Sayisi: %d\n", kitaplar2[i].sayfaSayisi );
            printf("Kitabin ISBN No 'su: %s\n", kitaplar2[i].ISBNno );
            
            if ( kitaplar2[ i ].KitapDurum == 1 )
            {
                printf("Kitabin Durumu: Odunc Alindi...\n");
            }
            else
            {
                printf("Kitabin Durumu: Odunc Verilebilinir...\n");
            }

            printf("\n");
            kontrol = 1;

        }

    }

    if ( kontrol == 0 )
    {
        printf("Aradiginiz Kitap Kutuphane Otomasyon Sistemimizde Bulunmamaktadir, Maalesef...\n");
    }
    
}

void KitapSil( Kitaplar kitaplar2[], int *index )
{
    int sira;
    printf("Yukarıdaki Kitaplardan Silmek Istediginiz Kitabin Sirasini Giriniz: ");
    scanf( "%d", &sira );
    getchar();

    if (sira < 1 || sira > *index) 
    {
        printf("Gecersiz sira numarasi!\n");
    }
    else 
    {
        int hedef = sira - 1;

        printf("Kutuphane Otomasyon Sistemimizden Silinen Kitap: %s\n", kitaplar2[*index - 1].kitapAdi);

        for (int i = hedef; i < (*index) - 1; i++) 
        {
            kitaplar2[i] = kitaplar2[i + 1];
        }      

        (*index)--;

    }
}

void KitapGuncelle( Kitaplar kitaplar2[], int *index )
{
    int sira;
    printf("Yukarıdaki Kitaplardan Guncellemek Istediginiz Kitabin Sirasini Giriniz: ");
    scanf("%d", &sira );
    getchar();

    if (sira < 1 || sira > *index) 
    {
        printf("Gecersiz kitap sirasi!\n");
    }
    else
    { 

        printf("Kutuphanemize Daha Once Eklemis Oldugunuz %s Kitabinin Yerine Girmek Istediginiz Kitabin Adini Giriniz: ", kitaplar2[ sira - 1 ].kitapAdi );
        scanf("%[^\n]", kitaplar2[ sira - 1 ].kitapAdi);
        getchar();

        printf("Kutuphanemize Daha Once Eklemis Oldugunuz %s Kitap Yazarinin Yerine Girmek Istediginiz Kitabin Yazarinin Adini Giriniz: ", kitaplar2[ sira - 1 ].yazarAdi );
        scanf("%[^\n]", kitaplar2[ sira - 1 ].yazarAdi );
        getchar();

        printf("Kutuphanemize Daha Once Eklemis Oldugunuz %d Kitap Sayfasinin Yerine Girmek Istediginiz Kitabin Sayfa Sayisi Giriniz: ", kitaplar2[ sira - 1 ].sayfaSayisi );
        scanf("%d", &kitaplar2[ sira - 1 ].sayfaSayisi );
        getchar();

        printf("Kutuphanemize Daha Once Eklemis Oldugunuz %s Kitap ISBN No 'su Yerine Girmek Istediginiz Kitabin ISBN No 'sunu Giriniz: ", kitaplar2[ sira - 1 ].ISBNno );
        scanf("%[^\n]", kitaplar2[ sira - 1 ].ISBNno );
        getchar();

        printf("Verilerini Girdiginiz Kitabiniz Kutuphanemize Basarili Bir Sekilde Guncellendi, Tebrikler...\n");

    }

}

void KitapOduncAl( Kitaplar kitaplar2[], Kullanici kullanici2[], int *kitaplarIndex, int *kullaniciIndex )
{
    int kitapSira;
    
    printf("\n\nYukarıdaki Kitaplardan Odunc Almak Istediginiz Kitabin Sirasini Giriniz: ");
    scanf("%d", &kitapSira );
    strcpy( kullanici2[ *kullaniciIndex ].AlinanKitapAdi, kitaplar2[ kitapSira - 1 ].kitapAdi );

    kitaplar2[ kitapSira - 1 ].KitapDurum = 1;

}

void KitapIadeEt( Kitaplar kitaplar2[], Kullanici kullanici2[], int *kitaplarIndex, int *kullaniciIndex )
{
    int kitapSira;
    
    printf("Odunc Alip Iade Etmek Istediginiz Kitabin Sirasini Giriniz: ");
    scanf("%d", &kitapSira );
    strcpy( kullanici2[ *kullaniciIndex ].AlinanKitapAdi, " " );

    kitaplar2[ kitapSira - 1 ].KitapDurum = 0;
}