import { useState, useEffect } from 'react';
import {Container, Navbar} from 'react-bootstrap';
import {useParams} from "react-router-dom";
import NavigationBar from "../Navbar/NavigationBar.jsx";

function NewsArticle() {
    const [newsData, setNewsData] = useState(null);
    const { id } = useParams();
    useEffect(() => {
        // Fetch the news article data when the component mounts
        fetch(`/api/news/${id}`)
            .then(response => {
                if (!response.ok) {
                    throw new Error('Failed to fetch news article');
                }
                return response.json();
            })
            .then(data => {
                setNewsData(data);
            })
            .catch(error => {
                console.error('Error fetching news article:', error);
                // You may want to handle error state here
            });
    }, [id]);

    // Render loading state if newsData is null
    if (!newsData) {
        return <div>Loading...</div>;
    }

    return (
        <>
            <NavigationBar></NavigationBar>
            <Container className="news-article">
                <h1>{newsData.title}</h1>
                <Container>{newsData.content}</Container>
            </Container>
        </>
    );
}

export default NewsArticle;
