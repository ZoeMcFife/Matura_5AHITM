import { Button, Container } from 'react-bootstrap';
import { Link } from 'react-router-dom';

function NewsArticlePreview({ id, title, content }) {
    const handleDelete = () => {
        deleteNews(id);
    };

    const deleteNews = (id) => {
        fetch(`/api/news/${id}`, {
            method: 'DELETE'
        })
            .then(response => {
                if (response.ok) {
                    alert('News article deleted successfully!');
                    // You may want to handle refreshing the news page or updating state here
                } else {
                    alert('Failed to delete news article.');
                }
            })
            .catch(error => {
                console.error('Error deleting news article:', error);
                alert('An error occurred while deleting the news article.');
            });
    };

    return (
        <Container className="news-article-preview">
            <h2>{title}</h2>
            <div>{content}</div>
            <div className="buttons-container">
                <Button title="Delete" onClick={() => handleDelete(id)} className="delete-button">Delete News</Button>
                <Link to={`/news/${id}`}><Button className="view-button">View</Button></Link>
            </div>
        </Container>
    );
}

export default NewsArticlePreview;
