<style>

@font-face {
  font-family: 'TheRumIsGone';
  src: url('TheRumIsGone.ttf') format('truetype');
  font-weight: normal;
  font-style: normal;
}

body 
{
  counter-reset: h1;
}

h1 {
  counter-reset: h2;
  font-family: 'TheRumIsGone', serif;
  text-shadow: 2px 2px 4px #ccc;
}

h2 
{
  counter-reset: h3;
  border-bottom: 2px solid #ffa500;
}

h3 {
  counter-reset: h4;
}

h4 {
  font-size: 1.2rem;
}

h1::before {
  counter-increment: h1;
  content: counter(h1) ". ";
}
h2::before {
  counter-increment: h2;
  content: counter(h1) "." counter(h2) " ";
}
h3::before {
  counter-increment: h3;
  content: counter(h1) "." counter(h2) "." counter(h3) " ";
}
h4::before {
    counter-increment: h4;
    content: counter(h1) "." counter(h2) "." counter(h3) "." counter(h4) " ";
}

</style>

# Table of Contents

- [Table of Contents](#table-of-contents)
- [🌐 Netzwerk und Webprogrammierung](#-netzwerk-und-webprogrammierung)
  - [🧑‍🤝‍🧑 Client - Server Konzept](#-client---server-konzept)
    - [1. Grundprinzip: Request–Response](#1-grundprinzip-requestresponse)
    - [Request–Response](#requestresponse)
    - [Typische Protokolle \& Ports](#typische-protokolle--ports)
    - [Architekturvarianten](#architekturvarianten)
    - [Vorteile \& Nachteile](#vorteile--nachteile)
    - [Sicherheit \& Authentifizierung](#sicherheit--authentifizierung)
    - [Beispiele aus der Praxis](#beispiele-aus-der-praxis)
    - [Skalierung \& Performance](#skalierung--performance)
    - [Ausblick: Microservices \& Serverless](#ausblick-microservices--serverless)
  - [🌐 ASP.NET Core API](#-aspnet-core-api)
    - [📡 RestAPI](#-restapi)
    - [⚙️ WebServer Configuration](#️-webserver-configuration)
    - [🧪 API Testen](#-api-testen)
      - [🧰 Postman](#-postman)
      - [🧭 Swagger](#-swagger)
  - [🔌 Sockets](#-sockets)
  - [🧵 Threads](#-threads)
    - [🧠 Threading in C#](#-threading-in-c)
      - [🔄 Synchronisation](#-synchronisation)
      - [⏳ Tasks](#-tasks)
    - [☕ Threading in Java](#-threading-in-java)


# 🌐 Netzwerk und Webprogrammierung

## 🧑‍🤝‍🧑 Client - Server Konzept
Das Client–Server-Modell ist das Fundament moderner Netzwerkarchitekturen. Dabei gibt es zwei Hauptrollen:

1. **Client**  
   - Initiator von Anfragen  
   - Benutzer- oder Frontend-Anwendung (Browser, Mobile App, Desktop-Client)  
   - Wartet auf Antworten vom Server  

2. **Server**  
   - Lauscht auf eingehende Verbindungswünsche  
   - Stellt Dienste, Daten und Ressourcen zur Verfügung  
   - Kann viele Clients parallel bedienen  

---

### 1. Grundprinzip: Request–Response

```text
Client                          Server
   | —— (1) Anfrage (Request) ——>  |
   |                               |
   | <—— (2) Antwort (Response) —— |
````

### Request–Response

**Request**  
Client schickt HTTP/FTP/SMTP-Anfrage oder RPC-Aufruf.  

**Response**  
Server verarbeitet die Anfrage und sendet das Ergebnis oder einen Fehlercode zurück.

---

### Typische Protokolle & Ports

| Protokoll     | Port (Standard) | Einsatzgebiet                    |
|---------------|-----------------|----------------------------------|
| HTTP / HTTPS  | 80 / 443        | Webseiten, REST-APIs             |
| FTP           | 21              | Dateitransfer                    |
| SMTP          | 25              | E-Mail Versand                   |
| DNS           | 53              | Namensauflösung                  |
| SSH           | 22              | Sichere Shell-Verbindungen       |

---

### Architekturvarianten

- **Einfacher Server**  
  - Single-Threaded, für kleine Last  
  - Beispiel: Embedded-Gerät mit Web-UI  

- **Multi-Threaded / Multi-Process**  
  - Jeder Client bekommt einen eigenen Thread/Prozess  
  - Besseres Parallel-Handling, aber hoher Speicher-/Thread-Overhead  

- **Event-Driven / Asynchron**  
  - Single-Thread, reagiert auf Events (z. B. Node.js, Nginx)  
  - Sehr skalierbar bei vielen kleinen Anfragen  

- **Load Balancing & Clustering**  
  - Mehrere Server-Instanzen hinter einem Load Balancer  
  - Hohe Verfügbarkeit & horizontale Skalierung  

---

### Vorteile & Nachteile

| Vorteile                                   | Nachteile                                     |
|--------------------------------------------|-----------------------------------------------|
| Klare Rollenverteilung                     | Single Point of Failure (bei Einzel-Server)   |
| Zentrale Wartung & Updates                 | Netzwerklatenz                                |
| Skalierung (vertikal & horizontal)         | Komplexität bei Clustering und Synchronisation|
| Sicherheit (Firewalls, Authentifizierung)  | Engpässe bei Datenbank oder Bandbreite        |

---

### Sicherheit & Authentifizierung

- **TLS/SSL**: Verschlüsselung der Kommunikation  
- **OAuth / JWT**: Token-basierte Authentifizierung  
- **API-Keys / Basic Auth**: Einfach, aber weniger sicher  
- **CORS**: Browser-seitige Richtlinien für Web-Clients  

---

### Beispiele aus der Praxis

- **Webbrowser ↔ Webserver** (Apache, Nginx)  
- **Mobile App ↔ REST-Backend** (JSON über HTTPS)  
- **IoT Sensor ↔ MQTT-Broker** (Publish/Subscribe statt reiner Request–Response)  
- **Datenbank-Client ↔ DB-Server** (JDBC, ODBC)  

---

### Skalierung & Performance

1. **Vertikal**: Mehr CPU/RAM pro Server  
2. **Horizontal**: Mehrere Server-Instanzen, Load Balancer dazwischen  
3. **Caching**: Redis/Memcached für häufige Anfragen  
4. **CDN**: Statische Assets näher zum Client bringen  

---

### Ausblick: Microservices & Serverless

- **Microservices**: Viele kleine Client-Server-Paare, die jeweils eine Domäne bedienen  
- **Serverless (FaaS)**: Entwickler schreiben Funktionen, das Cloud-Provider-Backend kümmert sich um Skalierung  


## 🌐 ASP.NET Core API
---

### 📡 RestAPI

### ⚙️ WebServer Configuration

### 🧪 API Testen

#### 🧰 Postman

#### 🧭 Swagger

---

## 🔌 Sockets
---

sdsds

---

## 🧵 Threads
---

### 🧠 Threading in C#

#### 🔄 Synchronisation

#### ⏳ Tasks

### ☕ Threading in Java

---

<p style="page-break-before: always;"></p>
<script>
  document.addEventListener("DOMContentLoaded", function() {
    // Create the button
    const btn = document.createElement("a");
    btn.href = "../index.html";  // adjust your path
    btn.textContent = "🏠 Home";
    // Style it so it truly fixes to the viewport
    Object.assign(btn.style, {
      position: "fixed",
      bottom: "1rem",
      right: "1rem",
      backgroundColor: "#c0392b",
      color: "#ffffff",
      padding: "0.5rem 0.75rem",
      fontFamily: "Arial, sans-serif",
      fontSize: "0.9rem",
      textDecoration: "none",
      borderRadius: "0.5rem",
      boxShadow: "0 2px 6px rgba(0,0,0,0.3)",
      zIndex: "9999",
      transition: "background-color 0.2s ease, transform 0.2s ease",
      display: "inline-block",
    });
    // Hover effects
    btn.addEventListener("mouseover", () => {
      btn.style.backgroundColor = "#922b21";
      btn.style.transform = "translateY(-2px)";
    });
    btn.addEventListener("mouseout", () => {
      btn.style.backgroundColor = "#c0392b";
      btn.style.transform = "none";
    });
    // Append to the real <body>
    document.body.appendChild(btn);
  });
</script>