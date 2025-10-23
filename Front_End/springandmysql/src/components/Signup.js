// Signup.js
import { useState } from "react";
import { useNavigate } from "react-router-dom";
import { useAuth } from "../contexts/AuthContext";

export default function Signup() {
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const { login } = useAuth();
  const navigate = useNavigate();

  const handleSignup = async () => {
    const res = await fetch("http://localhost:8000/signup", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ email, password }),
    });
    const data = await res.json();
    if (res.ok) {
      login(data.user);
      navigate("/profile");
    }
  };

  const handleBack = () => {
    navigate("/");
  }

  return (
    <div>
      <h2>회원가입</h2>
      <input value={email} onChange={(e) => setEmail(e.target.value)} placeholder="이메일" /> <br /><br />
      <input value={password} onChange={(e) => setPassword(e.target.value)} placeholder="비밀번호" type="password" /> <br /><br />
      <br /><br />
      <button onClick={handleSignup}>가입하기</button> <br /><br />
      <button onClick={handleBack}>뒤로가기</button>
    </div>
  );
}
