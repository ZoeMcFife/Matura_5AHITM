import React from 'react'
import ReactDOM from 'react-dom/client'
import Home from './Home.jsx'
import './index.css'
import 'bootstrap/dist/css/bootstrap.min.css';
import {BrowserRouter as Router, Route, Routes} from "react-router-dom";
import NewsPage from "./assets/NewsPage/NewsPage.jsx";
import Contact from "./assets/Contact.jsx";
import Accounts from "./assets/Accounts.jsx";
import NewsArticle from "./assets/NewsPage/NewsArticle.jsx";
import App from "./App.jsx";


ReactDOM.createRoot(document.getElementById('root')).render(
  <React.StrictMode>
      <App></App>
  </React.StrictMode>,
)
