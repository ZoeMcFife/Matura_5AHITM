import React, { useState } from 'react';
import { Container, Form, Button } from 'react-bootstrap';
import NavigationBar from '../Navbar/NavigationBar.jsx';

function AddNewsForm() {
    const [title, setTitle] = useState('');
    const [content, setContent] = useState('');

    const handleSubmit = (e) => {
        e.preventDefault();
        addNewsArticle({ title, content });
    };

    const addNewsArticle = (article) => {
        fetch('/api/News', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(article)
        })
            .then(response => {
                if (response.ok) {
                    alert('News article added successfully!');
                    setTitle('');
                    setContent('');
                } else {
                    alert('Failed to add news article.');
                }
            })
            .catch(error => {
                console.error('Error adding news article:', error);
                alert('An error occurred while adding the news article.');
            });
    };

    return (
        <>
            <Container>
                <h2>Add News Article</h2>
                <Form onSubmit={handleSubmit}>
                    <Form.Group controlId="formTitle">
                        <Form.Label>Title</Form.Label>
                        <Form.Control
                            type="text"
                            value={title}
                            onChange={(e) => setTitle(e.target.value)}
                            required
                        />
                    </Form.Group>
                    <Form.Group controlId="formContent">
                        <Form.Label>Content</Form.Label>
                        <Form.Control
                            as="textarea"
                            rows={5}
                            value={content}
                            onChange={(e) => setContent(e.target.value)}
                            required
                        />
                    </Form.Group>
                    <Button variant="primary" type="submit">
                        Add Article
                    </Button>
                </Form>
            </Container>
        </>
    );
}

export default AddNewsForm;
