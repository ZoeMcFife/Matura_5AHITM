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
---



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