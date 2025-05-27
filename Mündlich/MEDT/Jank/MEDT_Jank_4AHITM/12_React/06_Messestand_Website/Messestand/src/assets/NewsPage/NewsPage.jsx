import { useState, useEffect } from 'react';
import { Col, Container, Row } from 'react-bootstrap';
import NewsArticlePreview from './NewsArticlePreview.jsx';
import NavigationBar from '../Navbar/NavigationBar.jsx';
import AddNewsForm from "./AddNewsForm.jsx";

function NewsPage() {
    const [newsData, setNewsData] = useState([]);

    useEffect(() => {
        getAllNews().then(data => {
            setNewsData(data);
        });
    }, []);

    return (
        <>
            <NavigationBar />
            <Container>
                <Row>
                    {newsData.map(newsObject => (
                        <Col key={newsObject.id || newsObject.title}>
                            <NewsArticlePreview
                                id = {newsObject.id}
                                title={newsObject.title}
                                content={newsObject.content}
                            />
                        </Col>
                    ))}
                </Row>
            </Container>

            <Container>
                <AddNewsForm></AddNewsForm>
            </Container>


        </>
    );
}

function getAllNews() {
    return fetch('api/News')
        .then(r => r.json())
        .then(data => {
            return data;
        });
}

export default NewsPage;
