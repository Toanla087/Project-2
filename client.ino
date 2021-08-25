#include <SerialCommand.h> // Thêm vào sketch thư viện Serial Command
 
SerialCommand sCmd; // Khai báo biến sử dụng thư viện Serial Command
 

void setup() {
  //Khởi tạo Serial ở baudrate 9600 (trùng với HOST)
  Serial.begin(9600);
  
  pinMode(LED_BUILTIN,OUTPUT);
  
  
  // Một số hàm trong thư viện Serial Command
  
  sCmd.addCommand("LED_RED",   led_red);  // Khi có câu lệnh tên là LED_RED sẽ chạy hàm led_red
  
}
 
void loop() {
  sCmd.readSerial();
}
 
// hàm led_red sẽ được thực thi khi gửi hàm LED_RED
void led_red() {
  //Đoạn code này dùng để đọc TỪNG tham số. Các tham số mặc định có kiểu dữ liệu là "chuỗi"
  char *arg;
  arg = sCmd.next();
  
  int value = atoi(arg); // Chuyển chuỗi thành số
  digitalWrite(LED_BUILTIN,value);
}
