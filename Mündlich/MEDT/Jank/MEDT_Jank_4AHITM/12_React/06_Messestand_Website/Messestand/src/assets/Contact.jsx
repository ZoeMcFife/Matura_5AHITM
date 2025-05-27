import {Container} from "react-bootstrap";
import NavigationBar from "./Navbar/NavigationBar.jsx";

function Contact()
{
    return (
        <>
            <NavigationBar></NavigationBar>
            <Container>
                <section id="contact">
                    <h2>Contact us!</h2>
                    <form className="contact-form">
                        <label>
                            Name:
                            <input type="text" name="name"  required />
                        </label>
                        <label>
                            E-Mail:
                            <input type="email" name="email" required />
                        </label>
                        <label>
                            Message:
                            <textarea name="message" required />
                        </label>
                        <button type="submit">Send</button>
                    </form>
                </section>
            </Container>
        </>


    );
}

export default Contact;