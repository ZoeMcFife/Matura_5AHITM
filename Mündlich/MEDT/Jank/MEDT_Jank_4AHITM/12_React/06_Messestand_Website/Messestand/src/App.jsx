import NavigationBar from "./assets/Navbar/NavigationBar.jsx";

import React, { useEffect, useState } from 'react';
import {BrowserRouter as Router, Route, Routes} from "react-router-dom";
import NewsPage from "./assets/NewsPage/NewsPage.jsx";
import Contact from "./assets/Contact.jsx";
import Accounts from "./assets/Accounts.jsx";
import NewsArticle from "./assets/NewsPage/NewsArticle.jsx";
import Home from "./Home.jsx";
import User from "./User.js";

function App()
{
    const [user, setUser] = useState(new User())

    return (
        <>
            <Router>
                <Routes>
                    <Route path="/" element={<Home/>}></Route>
                    <Route path="/News" element={<NewsPage/>}></Route>
                    <Route path="/Contact" element={<Contact/>}></Route>
                    <Route path="/Account" element={<Accounts user={user}/>}></Route>
                    <Route path="/news/:id" element={<NewsArticle/>} />
                </Routes>
            </Router>
        </>
    );
}

export default App
