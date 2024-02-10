// Definisikan pin yang terhubung ke sensor kelembapan tanah
const int pinSensorKelembapanTanah = A4;
// Definisikan pin yang terhubung ke relay
const int pinRelay = 13;

void setup() {
  // Mulai Serial untuk output debugging
  Serial.begin(9600);

  // Set pin relay sebagai output
  pinMode(pinRelay, OUTPUT);
}

void loop() {
  // Baca nilai analog dari sensor kelembapan tanah
  int nilaiKelembapanTanah = analogRead(pinSensorKelembapanTanah);

  // Konversi nilai analog ke persentase kelembapan (dengan rentang sensor tertentu)
  float persentaseKelembapan = map(nilaiKelembapanTanah, 0, 1023, 0, 100);

  // Tampilkan nilai kelembapan pada Serial Monitor
  Serial.print("Kelembapan Tanah: ");
  Serial.print(persentaseKelembapan);
  Serial.println("%");

  // Tentukan batas kelembapan untuk mengaktifkan atau mematikan relay
  int batasKering = 30; // Ganti dengan batas sesuai kebutuhan

  // Kontrol relay berdasarkan kelembapan tanah
  if (persentaseKelembapan < batasKering) {
    // Tanah kering, aktifkan relay
    digitalWrite(pinRelay, HIGH);
    Serial.println("Relay ON");
  } else {
    // Tanah basah, matikan relay
    digitalWrite(pinRelay, LOW);
    Serial.println("Relay OFF");
  }

  // Tunda selama beberapa detik sebelum membaca ulang
  delay(1000);
}
