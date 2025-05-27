import './App.css'
import React from "react";
import
{
    BrowserRouter as Router,
    Routes,
    Route
} from "react-router-dom";

import Home from './Components/Home.jsx';
import Contact from './Components/Contact.jsx';
import Error from './Components/Error.jsx';
import About from './Components/About.jsx';


function App()
{
    return (
        <Router>
            <Routes>
                <Route path="/" element={<Home/>}></Route>
                <Route path="/Contact" element={<Contact/>}></Route>
                <Route path="/About" element={<About/>}></Route>
                <Route path="*" element={<Error></Error>}></Route>
            </Routes>
        </Router>
    );
}

export default App
