
#include "RTClib.h"      // Kütüphanemizi ekliyoruz
#include <Wire.h>                              // Adafruit'in RTClib kütüphanesi
 
RTC_DS1307 rtc;          // Kütüphanemiz başlatılıyor
 
char HaftaninGunleri[7][12] = {"Pazar", "Pazartesi", "Salı",
     "Çarşamba", "Perşembe", "Cuma", "Cumartesi"};
 
void setup() {
  Serial.begin(9600);     // Seri Port Ekranı'nı başlatıyoruz
  if (!rtc.begin()) {     // Modüle bağlantı kontrol ediliyor
    Serial.println("RTC Bulunamadı!");
    while(1);
  }
  if (!rtc.isrunning()) { // RTC'nin ayarlı olup olmadığı kontrol ediliyor
    Serial.println("RTC çalışmıyor!");
    // Alttaki satır Arduino IDE'den gelen saat ve tarihi alarak RTC'yi ayarlar
    // Bu halde bir defalığına Arduino'ya yükledikten sonra satırı başına //
    // koyarak yorum yapıp tekrar yüklemeliyiz.
    // Aksi halde her açılışta tekrar saat yüklemeye çalışır.
 //   rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
   // 1 Mart 2022, saat 3'e ayarlamak isterseniz:
   // rtc.adjust(DateTime(2022, 3, 1, 3, 0, 0));
  }
}
void loop() {
  DateTime now = rtc.now();                  // Güncel saati bu satırda okuyoruz
  if (now.day() < 10) {Serial.print("0");}   // 3. ayı 03 olarak gösterelim
  Serial.print(now.day(), DEC);              // Günü yazalım
  Serial.print(".");
  if (now.month() < 10) {Serial.print("0");}
  Serial.print(now.month(), DEC);            // Ayı yazalım
  Serial.print(".");
  Serial.print(now.year(), DEC);             // Yılı yazalım
  Serial.print(" ");
  Serial.print(HaftaninGunleri[now.dayOfTheWeek()]); // Günün adı
  Serial.print(" | ");
  if (now.hour() < 10) {Serial.print("0");}
  Serial.print(now.hour(), DEC);             // Saati yazalım
  Serial.print(":");
  if (now.minute() < 10) {Serial.print("0");}
  Serial.print(now.minute(), DEC);           // Dakikayı yazalım
  Serial.print(":");
  if (now.second() < 10) {Serial.print("0");}
  Serial.println(now.second(), DEC);         // Saniyeyi yazalım
  delay(1000);
}
