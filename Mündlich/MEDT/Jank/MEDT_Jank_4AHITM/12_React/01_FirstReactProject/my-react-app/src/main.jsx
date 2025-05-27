import React from 'react'
import ReactDOM from 'react-dom/client'

export default function Greeter (props)
{
    let [greeting, setGreeting] = React.useState("");

    function handleGreetClick()
    {
        alert(`Hello, ${greeting}`);
    }

    const charsRemaining = props.maxLength - greeting.length;
    const greetingInvalid = greeting.length === 0 || charsRemaining < 0;
    const tooManyChars = greeting.length >= props.maxLength;

    if (tooManyChars)
    {
        greeting = greeting.substring(0, 19);
    }

    return (
        <div className="container">

            <h2>Ahoy!</h2>

            <div className="input-container">
                <input
                    type="text"
                    placeholder="Enter your greeting..."
                    value={greeting}
                    onChange={(e) => setGreeting(e.target.value)}
                />
            </div>

            <span>{charsRemaining}</span>

            <div className="button-container">
                <button disabled={greetingInvalid} onClick={handleGreetClick}>Yarr</button>
            </div>
        </div>
    );
}

ReactDOM.createRoot(document.getElementById('root')).render(
    <React.StrictMode>
        <Greeter maxLength={20}/>
    </React.StrictMode>,
)