import './App.css'
import Board from "./components/Board/Board.jsx";
import Game from "./components/Game/Game.jsx";

function App() {

  return (
    <>
      <h1>Tic Tac Toe</h1>

      <div className={"BoardContainer"}>
        <Game></Game>
      </div>
    </>
  )
}

export default App
