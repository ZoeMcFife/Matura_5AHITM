<style>
body {
  counter-reset: h1;
}
h1 {
  counter-reset: h2;
}
h2 {
  counter-reset: h3;
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
</style>

---
# Gestaltung von Web- und Mobilen Anwendungen
---
## ASP.NET CORE
---
### Templates

### RazorPages

#### Razor-Syntax

### UserControls

### Werteübergabe

### Datenbindung

### Validation

### Konzept und Funktionsweise

### Event-Handling 

---




## Android

---


### Activities

### Intents

### Fragments

### Lifecycle von Activity und Fragmenten

### Android Manifest

### Ressourcen

### Android-Workflow (Instatllation Android Studio)

