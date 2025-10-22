import { BrowserRouter as Router, Routes, Route } from "react-router-dom";
import Login from "./components/Login";
import Home from "./components/Home";
import Signup from "./components/Signup";
import Profile from "./components/Profile";
import ProtectedRoute from "./components/ProtectedRoute";

function App() {
  return (
    <Router>
      <Routes>
        <Route path="/" element={<Login />} />
        <Route path="/new" element={<Signup />}/>
        {/* /home 경로에 접근 시 ProtectedRoute 적용 */}
        <Route
          path="/home"
          element={
            <ProtectedRoute allowedRoles={['admin', 'user']}>
              <Home />
              <Profile />
            </ProtectedRoute>
          }
        />
        
        
      </Routes>
    </Router>
  );
}

export default App;
