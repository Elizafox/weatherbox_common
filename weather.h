/* weather.h - weather data storage structure for I2C
 * Created by: Elizabeth Myers <elizabeth.jennifer.myers@gmail.com>
 * Dedicated to the public domain.
 */
#ifndef WEATHER_H
#define WEATHER_H

class Weather {
private:
  // WARNING: THIS MUST BE CHANGED ON BOTH SIDES
  struct packet_t {
    struct tod_t {
      uint8_t day;
      uint8_t month;
      uint16_t year;
      uint8_t hour;
      uint8_t minute;
      uint8_t second;
      uint16_t msec;
    } t;	
    struct weather_t {
      int16_t temperature;         // Multiplied by 100
      uint16_t humidity;           // Multiplied by 100
      uint16_t pressure;           // Multiplied by 100
      uint16_t aqi;                // Multiplied by 100
      uint16_t co2e;               // Multiplied by 100
      uint16_t breath_voce;        // Multiplied by 100
      uint8_t uv;
      uint16_t wind;               // Multiplied by 100
      uint16_t wind_direction;     // Multiplied by 100
      uint16_t rainfall_per_hour;  // Multiplied by 100
    } w;
  } __attribute__((aligned(4))) packet;

public:
  static constexpr size_t packet_size{sizeof(packet_t)};

  void from_data(byte din[]) {
    memcpy(&packet, din, packet_size);
  }

  const byte* to_data() {
    return reinterpret_cast<const byte*>(&packet);
  }

  Weather(byte din[]) {
    from_data(din);
  }

  Weather() {
    memset(&packet, 0, sizeof(packet_t));
  }

  // Getter methods //

  uint8_t get_day() {
    return packet.t.day;
  }
  
  uint8_t get_month() {
    return packet.t.month;
  }

  uint16_t get_year() {
    return packet.t.year;
  }

  uint8_t get_hour() {
    return packet.t.hour;
  }

  uint8_t get_minute() {
    return packet.t.minute;
  }

  uint8_t get_second() {
    return packet.t.second;
  }

  uint16_t get_msec() {
    return packet.t.msec;
  }

  float get_temperature() {
    return packet.w.temperature / 100.0;
  }
  
  float get_humidity() {
    return packet.w.humidity / 100.0;
  }
  
  float get_pressure() {
    return packet.w.pressure / 100.0;
  }
  
  float get_aqi() {
    return packet.w.aqi / 100.0;
  }

  float get_co2e() {
    return packet.w.co2e / 100.0;
  }

  float get_breath_voce() {
    return packet.w.breath_voce / 100.0;
  }
  
  uint8_t get_uv() {
    return packet.w.uv;
  }
  
  float get_wind() {
    return packet.w.wind / 100.0;
  }
  
  float get_wind_direction() {
    return packet.w.wind_direction / 100.0;
  }
  
  float get_rainfall_per_hour() {
    return packet.w.rainfall_per_hour / 100.0;
  }

  // Setter methods //

  void set_day(uint8_t day) {
    packet.t.day = day;
  }
  
  void set_month(uint8_t month) {
    packet.t.month = month;
  }

  void set_year(uint16_t year) {
    packet.t.year = year;
  }

  void set_hour(uint8_t hour) {
    packet.t.hour = hour;
  }

  void set_minute(uint8_t minute) {
    packet.t.minute = minute;
  }

  void set_second(uint8_t second) {
    packet.t.second = second;
  }

  void set_msec(uint16_t msec) {
    packet.t.msec = msec;
  }

  void set_temperature(float temperature) {
    packet.w.temperature = round(temperature * 100.0);
  }
  
  void set_humidity(float humidity) {
    packet.w.humidity = round(humidity * 100.0);
  }
  
  void set_pressure(float pressure) {
    packet.w.pressure = round(pressure * 100.0);
  }
  
  void set_aqi(float aqi) {
    packet.w.aqi = round(aqi * 100.0);
  }

  void set_co2e(float co2e) {
    packet.w.co2e = round(co2e * 100.0);
  }

  void set_breath_voce(float breath_voce) {
    packet.w.breath_voce = round(breath_voce * 100.0);
  }
  
  void set_uv(uint8_t uv) {
    packet.w.uv = uv;
  }
  
  void set_wind(float wind) {
    packet.w.wind = round(wind * 100.0);
  }
  
  void set_wind_direction(float direction_) {
    packet.w.wind_direction = round(direction_ * 100.0);
  }
  
  void set_rainfall_per_hour(float rainfall) {
    packet.w.rainfall_per_hour = round(rainfall * 100.0);
  }
};

#endif // WEATHER_H
