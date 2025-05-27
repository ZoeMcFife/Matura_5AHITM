import {Container} from "react-bootstrap";
import AccountCreationForm from "./Login/AccountCreationForm.jsx";
import LoginForm from "./Login/LoginForm.jsx";
import React from "react";
import NavigationBar from "./Navbar/NavigationBar.jsx";

function Accounts({user})
{
    return(
        <>
            <NavigationBar></NavigationBar>

            <Container>
                <AccountCreationForm></AccountCreationForm>
            </Container>

            <Container>
                <LoginForm user={user}></LoginForm>
            </Container>
        </>
    );
}

export default Accounts