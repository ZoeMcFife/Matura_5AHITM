import {Button, Form, FormLabel} from "react-bootstrap";

function AccountCreationForm()
{
    return(
        <>
            <h1>Create Account</h1>
            <Form>
                <Form.Group controlId="formUsername">
                    <Form.Label>Username</Form.Label>
                    <Form.Control type="text" placeholder="Enter username" />
                </Form.Group>

                <Form.Group controlId="formPassword">
                    <Form.Label>Password</Form.Label>
                    <Form.Control type="password" placeholder="Password" />
                </Form.Group>

                <Button variant="primary" type="button" onClick={createAccount}>
                    Create Account
                </Button>

                <FormLabel>Status: <p id={"account-creation-status"}></p></FormLabel>
            </Form>
        </>
    );
}

function createAccount()
{
    let username = document.getElementById("formUsername").value;
    let password = document.getElementById("formPassword").value;

    fetch('/api/user',
        {method: "POST", headers: {"Content-Type": "application/json"},
            body: JSON.stringify({name: username, password: password})})
        .then(r =>
        {
            if (r.ok)
            {
                document.getElementById("account-creation-status").innerText = "Success!";
            }
            else
            {
                document.getElementById("account-creation-status").innerText = "There was a problem! :(";
            }
        });
}

export default AccountCreationForm