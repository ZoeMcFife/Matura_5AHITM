import {Button, Form, FormLabel} from "react-bootstrap";

function LoginForm({user})
{
    return(
        <>
            <h1>Log In</h1>
            <Form>
                <Form.Group controlId="formLoginUsername">
                    <Form.Label>Username</Form.Label>
                    <Form.Control type="text" placeholder="Enter username" />
                </Form.Group>

                <Form.Group controlId="formLoginPassword">
                    <Form.Label>Password</Form.Label>
                    <Form.Control type="password" placeholder="Password" />
                </Form.Group>

                <Button variant="primary" type="button" onClick={authenticate}>
                    Log In
                </Button>

                <FormLabel>Status: <p id={"account-login-status"}></p></FormLabel>

            </Form>
        </>
    );
}

function authenticate()
{
    let username = document.getElementById("formLoginUsername").value;
    let password = document.getElementById("formLoginPassword").value;

    fetch('api/user/authenticate/' + username + "/" + password)
        .then(r =>
        {
            if (r.ok)
            {
                document.getElementById("account-login-status").innerText = "Success!";
            }
            else
            {
                document.getElementById("account-login-status").innerText = "Login failed :(";
            }
        });

    let user = fetch('api/user/GetUserByName/' + username);

    console.log(user)
}

export default LoginForm