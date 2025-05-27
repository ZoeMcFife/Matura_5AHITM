import {Container, Image, Nav, Navbar} from "react-bootstrap";
import './NavigationBar.css';



function NavigationBar()
{
    return (
        <>
            <Navbar bg="dark" variant="dark" expand="lg">
                <Container>
                    <Navbar.Brand href="/">Galactic News</Navbar.Brand>
                    <Navbar.Toggle aria-controls="basic-navbar-nav" />
                    <Navbar.Collapse id="basic-navbar-nav">
                        <Nav className="me-auto">
                            <Nav.Link href="/">Home</Nav.Link>
                            <Nav.Link href="/News">News</Nav.Link>
                            <Nav.Link href="/Contact">Contact</Nav.Link>
                            <Nav.Link href="/Account">Create Account</Nav.Link>
                        </Nav>
                    </Navbar.Collapse>
                </Container>
            </Navbar>
        </>
    )
}

export default NavigationBar