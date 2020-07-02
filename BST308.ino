/*  Numara Ad Soyad
  Kesan Yusuf Capraz Uygulamali Bilimler Yuksekokulu
  Bilgisayar Teknolojileri ve Bilisim Sistemleri Bolumu
  BST308 Mikroislemciler Dersi
  2019-2020 Egitim Ogretim Yili Bahar Yariyili Final Odevi Projesi
  (Otomatik Satis makinesi - Vending Machine)
  Credit : Murat Çiçek 2020 june
*/

#include <LiquidCrystal.h>
#define birlira 17
#define ellikurus 18
#define yirmibeskurus 19
#define onkurus 20
#define beskurus 21
#define sual A15
#define kekal A14
#define gofretal A13
#define cikolataal A12
#define redPin A4
#define greenPin A5
#define bluePin A6
#define yellowPin A7
#define pyellowPin 8
#define pbluePin 9
#define predPin 10
#define pgreenPin 11
LiquidCrystal lcd(34, 35, 36, 38, 39, 40, 41, 42, 43, 44, 45);

// Satilan urunlerin fiyatlari (calisma boyunca sabit)
const float fiyat_su = 1.50f;
const float fiyat_kek = 2.25f;
const float fiyat_gofret = 3.75f;
const float fiyat_cikolata = 4.15f;

// Urun stok miktarlari bu degiskenlerde tutulacak
int stok_su;
int stok_kek;
int stok_gofret;
int stok_cikolata;

// Cihaz kasasında hangi para urunden kacar adet oldugu tutulacak
int kasa_5kr;
int kasa_10kr;
int kasa_25kr;
int kasa_50kr;
int kasa_1tl;

// Aktif bakiye miktari bu degiskende tutulacak
float bakiye;
void paraUstu() {
  
  if(bakiye<=0){
      bakiye=0;
      islemler();
  }
  while (bakiye > 0.00f) {
    if (bakiye >= 1.00f) {
      bakiye -= 1.0f;

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("1 TL VERiLDi");
      lcd.setCursor(0, 1);
      lcd.print(bakiye, 2);
      // 1 saniye boyunca ürün ledi yanacak
      digitalWrite(predPin, HIGH);
      delay(1000);
      digitalWrite(predPin, LOW);
      kasa_1tl--; // kasadan para eksiltiyoruz
      delay(500);
      paraUstu();
    } else if (bakiye >= 0.50f) {
      bakiye -= 0.50f;

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("50 Krs VERiLDi");
      lcd.setCursor(0, 1);
      lcd.print(bakiye, 2);
      // 1 saniye boyunca ürün ledi yanacak
      digitalWrite(pgreenPin, HIGH);
      delay(1000);
      digitalWrite(pgreenPin, LOW);
      delay(500);
      kasa_50kr--; // kasadan para eksiltiyoruz
      paraUstu();
    }else if (bakiye >= 0.25f) {
      bakiye -= 0.25f;

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("25 Krs VERiLDi");
      lcd.setCursor(0, 1);
      lcd.print(bakiye, 2);
      // 1 saniye boyunca ürün ledi yanacak
      digitalWrite(pbluePin, HIGH);
      delay(1000);
      digitalWrite(pbluePin, LOW);
      delay(500); 
      kasa_25kr--;  // kasadan para eksiltiyoruz
      paraUstu();
    }else if (bakiye >= 0.10f) {
      bakiye -= 0.10f;

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("10 Krs VERiLDi");
      lcd.setCursor(0, 1);
      lcd.print(bakiye, 2);
      // 1 saniye boyunca ürün ledi yanacak
      digitalWrite(pbluePin, HIGH);
      delay(1000);
      digitalWrite(pbluePin, LOW);
      delay(500);
      kasa_10kr--;  // kasadan para eksiltiyoruz
      paraUstu();
    }else if (bakiye >= 0.050f); {
      bakiye -= 0.05f;

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("5 Krs VERiLDi");
      lcd.setCursor(0, 1);
      lcd.print(bakiye, 2);
      // 1 saniye boyunca ürün ledi yanacak
      digitalWrite(pyellowPin, HIGH);
      delay(1000);
      digitalWrite(pyellowPin, LOW);
      delay(500);
      kasa_5kr--;  // kasadan para eksiltiyoruz
      paraUstu();}
    }
}
void islemler() {
  if (digitalRead(birlira) == LOW) //1 lira
  {
    bakiye += 1.00f;
    delay(300);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("URUN SECINIZ    ");
    lcd.setCursor(0, 1);
    lcd.print("Bakiye: ");
    lcd.print(bakiye, 2);
    lcd.print(" TL  ");
  } else if (digitalRead(ellikurus) == LOW) //50 kuruş 
  {
    bakiye += 0.50f;
    delay(300);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("URUN SECINIZ    ");
    lcd.setCursor(0, 1);
    lcd.print("Bakiye: ");
    lcd.print(bakiye, 2);
    lcd.print(" TL  ");
  } else if (digitalRead(yirmibeskurus) == LOW) //20 kuruş
  {
    bakiye += 0.25f;
    delay(300);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("URUN SECINIZ    ");
    lcd.setCursor(0, 1);
    lcd.print("Bakiye: ");
    lcd.print(bakiye, 2);
    lcd.print(" TL  ");
  } else if (digitalRead(onkurus) == LOW) //10 kuruş
  {
    bakiye += 0.10f;
    delay(300);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("URUN SECINIZ    ");
    lcd.setCursor(0, 1);
    lcd.print("Bakiye: ");
    lcd.print(bakiye, 2);
    lcd.print(" TL  ");
  } else if (digitalRead(beskurus) == LOW) //5 kuruş
  {
    bakiye += 0.05f;
    delay(300);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("URUN SECINIZ    ");
    lcd.setCursor(0, 1);
    lcd.print("Bakiye: ");
    lcd.print(bakiye, 2);
    lcd.print(" TL  ");
  }
  if (digitalRead(sual) == LOW) // su alımı
  {
    if (bakiye >= 1.50f) {
      bakiye -= 1.50f;
      delay(300);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("URUN SECINIZ    ");
      lcd.setCursor(0, 1);
      lcd.print("Bakiye: ");
      lcd.print(bakiye, 2);
      lcd.print(" TL  ");
      digitalWrite(redPin, HIGH);
      delay(300);
      digitalWrite(redPin, LOW);
      paraUstu();
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("UYARI    ");
      lcd.setCursor(0, 1);
      lcd.print("BAKIYE YETERSIZ ");
      delay(500);
    }
  }

  if (digitalRead(kekal) == LOW) // kek alımı
  {
    if (bakiye >= 2.25f) {
      bakiye -= 2.25f;
      delay(300);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("URUN SECINIZ    ");
      lcd.setCursor(0, 1);
      lcd.print("Bakiye: ");
      lcd.print(bakiye, 2);
      lcd.print(" TL  ");
      digitalWrite(greenPin, HIGH);
      delay(300);
      digitalWrite(greenPin, LOW);
      paraUstu();
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("UYARI    ");
      lcd.setCursor(0, 1);
      lcd.print("BAKIYE YETERSIZ ");
      delay(500);
    }

  }
  if (digitalRead(gofretal) == LOW) // gofret alımı
  {
    if (bakiye >= 3.75f) {
      bakiye -= 3.75f;
      delay(300);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("URUN SECINIZ    ");
      lcd.setCursor(0, 1);
      lcd.print("Bakiye: ");
      lcd.print(bakiye, 2);
      lcd.print(" TL  ");
      digitalWrite(bluePin, HIGH);
      delay(300);
      digitalWrite(bluePin, LOW);
      paraUstu();
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("UYARI    ");
      lcd.setCursor(0, 1);
      lcd.print("BAKIYE YETERSIZ ");
      delay(500);
      
    }
  }
  if (digitalRead(cikolataal) == LOW) //çikolata alımı
  {
    if (bakiye >= 4.15f) {
      bakiye -= 4.15f;
      delay(300);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("URUN SECINIZ    ");
      lcd.setCursor(0, 1);
      lcd.print("Bakiye: ");
      lcd.print(bakiye, 2);
      lcd.print(" TL  ");
      digitalWrite(yellowPin, HIGH);
      delay(300);
      digitalWrite(yellowPin, LOW);
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("UYARI    ");
      lcd.setCursor(0, 1);
      lcd.print("BAKIYE YETERSIZ ");
      delay(500);

    }

  } else {}
}
void setup() {

  lcd.begin(16, 2);

  // Baslangictaki urun stoklari
  // test icin degistirebilirsiniz
  stok_su = 13;
  stok_kek = 7;
  stok_gofret = 11;
  stok_cikolata = 9;

  // Baslangicta kasada bulunan paralar
  // test icin degistirebilirsiniz
  kasa_5kr = 20;
  kasa_10kr = 15;
  kasa_25kr = 10;
  kasa_50kr = 10;
  kasa_1tl = 10;

  // Bakiye baslangicta sifir
  bakiye = 0.0;
  pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(A15, INPUT_PULLUP);
  pinMode(A14, INPUT_PULLUP);
  pinMode(A13, INPUT_PULLUP);
  pinMode(A12, INPUT_PULLUP);
  pinMode(redPin, OUTPUT); //su satın alındığında kırmızı ısık yanar 
  pinMode(greenPin, OUTPUT); //kek satın alındığında kırmızı ısık yanar 
  pinMode(bluePin, OUTPUT); //gofret satın alındığında kırmızı ısık yanar 
  pinMode(yellowPin, OUTPUT); //çikolata satın alındığında kırmızı ısık yanar 
  pinMode(pyellowPin, OUTPUT); // para üstü 1 lira verince yanar
  pinMode(pbluePin, OUTPUT); // para üstü 50 kuruş verince yanar
  pinMode(predPin, OUTPUT); // para üstü 25 kurus verince yanar
  pinMode(pgreenPin, OUTPUT); // para üstü 10 kuruş verince yanar
}

void loop() {

  // mevcut durumla ilgili bilgi yaz
  lcd.setCursor(0, 0);
  lcd.print("URUN SECINIZ    ");

  // atilan para tutarini (bakiyeyi) goster
  lcd.setCursor(0, 1);
  lcd.print("Bakiye: ");
  lcd.print(bakiye, 2);
  lcd.print(" TL  ");

  
    islemler();  

}
