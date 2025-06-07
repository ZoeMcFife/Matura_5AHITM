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
- [🏛️ Softwarearchitektur und Design Patterns](#️-softwarearchitektur-und-design-patterns)
  - [🧠 Design Patterns](#-design-patterns)
    - [⚙️ C#](#️-c)
    - [☕ Java](#-java)
    - [📱 Android](#-android)
  - [🧭 MVVM WPF](#-mvvm-wpf)
    - [MVVM](#mvvm)
    - [View](#view)
    - [ViewModel](#viewmodel)
    - [Model](#model)
    - [Example](#example)
  - [🏗️ MVC](#️-mvc)
  - [📱 Android](#-android-1)
  - [🏗️ 3 Schichten Architektur](#️-3-schichten-architektur)

# 🏛️ Softwarearchitektur und Design Patterns

## 🧠 Design Patterns
---

### ⚙️ C#

### ☕ Java

### 📱 Android

---

## 🧭 MVVM WPF

WPF is kinda cringe ngl

---

### MVVM 

![alt text](image.png)

### View

- Visual Element
- View Model
  - Data Context
- Controls
  - Data Bound to Properties and Commands in the View Model
- Code Behind
  - Only UI Logic

### ViewModel

- non visual
- presentation logic
- independent of view and model
- doesnt reference the view
- properties and commands
- **INotifyPropertyChanged** / **INotifyCollectionChanged**
- view interaction

### Model

- non-visual 
- business logic
- application data
- no reference on the view or viewmodel
- used with sql, xml or other data stuff

### Example

![alt text](image-1.png)

![alt text](image-2.png)

![alt text](image-3.png)

![alt text](image-4.png)


---

## 🏗️ MVC
---

---

## 📱 Android
---

## 🏗️ 3 Schichten Architektur

![alt text](image-10.png)