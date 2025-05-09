# 📚 Kütüphane Otomasyon Sistemi

Bu proje, C programlama dili ile geliştirilmiş basit bir kütüphane otomasyon sistemidir. Konsol üzerinden çalışan bu sistem, kullanıcıların kitap bilgilerini yönetmelerini sağlar.

## 🚀 Özellikler

- Kitap ekleme, listeleme, arama, silme ve güncelleme
- Kullanıcı girişi (kullanıcı adı ve şifre kontrolü)
- Kitapların mevcut durumu hakkında bilgi sunar

## 🛠️ Kurulum ve Çalıştırma

1. Proje dosyasını indirin veya klonlayın:
   ```bash
   git clone https://github.com/kasm45/kutuphane_otomasyon.git
   cd kutuphane_otomasyon
   ```

2. Derleyip çalıştırın:
   ```bash
   gcc kutuphaneotomasyon.c -o kutuphaneotomasyon
   ./kutuphaneotomasyon
   ```

## 📌 Kullanım Örneği (Konsol Çıktısı)

```
--- Kütüphane Otomasyon Sistemine Hoşgeldiniz ---
Kullanıcı Adı: admin
Şifre: ****

1. Kitap Ekle
2. Kitap Listele
3. Kitap Ara
4. Kitap Sil
5. Kitap Güncelle
6. Çıkış
Seçiminiz: 
```

## 🧱 Teknik Bilgiler

- **Programlama Dili**: C
- **Derleyici**: GCC
- **Veri Saklama**: Statik diziler (dynamic memory kullanılabilir şekilde genişletilebilir)
- **Güvenlik**: Giriş işlemi (şifre kontrolü), temel input doğrulaması

## 💡 Geliştirme Fikirleri

- Kitap bilgilerini dosyada saklama
- Kullanıcı ve admin rolleri ayırma
- Dinamik bellek yönetimi (malloc/free)
- Tarih/saat takibi ile ödünç alma sistemi

## 📄 Lisans

Bu proje MIT lisansı ile lisanslanmıştır.
