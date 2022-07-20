import './App.css';
import Blogs from './components/Blogs';
import Forms from './components/Forms';

function App() {
  return (
    <div className="App">
      <h1>List of blogs</h1>
      <Forms />
      <br></br>
      <Blogs />     
    </div>
  );
}

export default App;
