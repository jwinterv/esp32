# ESP32 WiFi Control Prototype  

🔹 *Basic web-controlled LED system serving as a foundation for IoT and automation studies*  

## 📋 About the Project  
A learning prototype developed by **IEEE Student Branch at Instituto Federal Fluminense** demonstrating:  
- ESP32 WiFi Access Point creation  
- Simple web interface for device control  
- HTML/image storage in flash memory using LittleFS
- State persistence example using NVS

  ## 🛠️ Current Features  
- Individual control of 5 LEDs (simulating relays)  
- Basic web pages (login, main menu, controls)  
- System maintains LED states after reboot  
- Local network operation without internet dependency 

## 🔧 Areas for Improvement  
1. **Real-time updates**  
   - Changes made by one user don't automatically reflect on other connected devices  

2. **Basic security**  
   - Hardcoded WiFi credentials  
   - No user authentication in web interface  

3. **Scalability**  
   - Connection stability degrades with multiple clients  
   - Needs better state management    

4. **Multi-user interface sync**  
   - Button states don't update across different user sessions
  
> **OBS**: You can customize the WiFi credentials and GPIO pins by modifying these values in the code:  
> ```cpp
> // Configuration (change before uploading):
> const char *ssid = "IEEE";         // WiFi name
> const char *pass = "12345678";     // WiFi password
> #define LD1 23                     // LED pin assignments
> #define LD2 22                     // (adjust as needed)
> ```
