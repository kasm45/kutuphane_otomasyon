Kütüphane Otomasyon Sistemi

Bu projede, C programlama dili kullanılarak basit bir kütüphane otomasyon sistemi geliştirilmiştir. Sistem, kitapların ve kullanıcıların bilgilerini tutarak kitap ekleme, silme, güncelleme, ödünç alma ve iade etme gibi işlevleri sunar. Konsol tabanlı bu uygulama sayesinde kullanıcı dostu bir kitap yönetim deneyimi hedeflenmiştir.

İçerik

Projenin Amacı

Kullanılan Veri Yapıları

Fonksiyonlar

Nasıl Derlenir ve Çalıştırılır

Geliştirme Fikirleri

Projenin Amacı

Bu projenin temel amacı, bir kütüphanede bulunan kitapların ve kullanıcıların bilgilerini bir dizide tutarak, bu veriler üzerinde işlemler yapabilen bir sistem oluşturmaktır. Proje sayesinde C dilinde diziler, yapılar, fonksiyonlar, bellek yönetimi ve kontrol yapıları gibi temel kavramları uygulamalı olarak pekleştirme fırsatı bulunur.

Kullanılan Veri Yapıları

Kitaplar yapısı:

typedef struct {
    char kitapAdi[100];
    char yazarAdi[100];
    int sayfaSayisi;
    char ISBNno[15];
    bool KitapDurum; // 0: Müsait, 1: Odunc Alınmış
} Kitaplar;

Kullanici yapısı:

typedef struct {
    char kullaniciAdi[50];
    char kullaniciSoyadi[50];
    char email[20];
    char telefon[11];
    char sifre[20];
    char AlinanKitapAdi[100];
} Kullanici;

Fonksiyonlar

Kullanıcı Menüsü

KullaniciAnaMenu() : Sisteme giriş, kayıt ve çıkış seçeneklerini sunar.

KullaniciEkle() : Yeni kullanıcı eklenmesini sağlar.

KullaniciKontrol() : Kullanıcı giriş bilgilerinin doğruluğunu kontrol eder.

Kitap Menüsü

AnaMenu() : Kitap işlemleri için ana menüyü gösterir.

KitapEkle() : Yeni kitap ekler.

KitapListele() : Tüm kitapları listeler.

KitapAra() : Belirli bir kitabı isme göre arar.

KitapSil() : Belirtilen kitabı listeden siler.

KitapGuncelle() : Mevcut bir kitabın bilgilerini günceller.

KitapOduncAl() : Seçilen kitabı odunc verir.

KitapIadeEt() : Odunc alınan kitabı iade eder.

Nasıl Derlenir ve Çalıştırılır

Kodu bir dosyaya kaydedin, örneğin: kutuphane.c

Terminal veya komut satırından şu komutu kullanarak derleyin:

gcc kutuphane.c -o kutuphane -lm

Ardından uygulamayı çalıştırın:

./kutuphane

Geliştirme Fikirleri

Verilerin dosyaya kaydedilmesi ve program kapansa bile korunması.

Daha güçlü şifreleme ve kimlik doğrulama sistemleri.

Arayüz için grafiksel uygulama (GTK, Qt vb.) geliştirilmesi.

Arama fonksiyonunun yazar adı, ISBN veya sayfa sayısı gibi farklı kritere göre genişletilmesi.

Kitaplara kategori etiketi eklenmesi ve filtreleme seçenekleri.

Bu proje bireysel olarak geliştirilmiştir ve eğitim amaçlıdır. Katkıda bulunmak isteyenler için geliştirilmeye açıktır.