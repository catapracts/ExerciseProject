// src/components/LoginPage.jsx
import { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { useAuth } from '../contexts/AuthContext';
import axios from '../axios';

function Login() {
  const [username, setUsername] = useState('');
  const [password, setPassword] = useState('');
  const [errorMessage, setErrorMessage] = useState(null);
  const [role, setRole] = useState('user');  // 기본 role은 일반 사용자
  const navigate = useNavigate();
  const { login } = useAuth();

  const handleLogin = async(e) => {
    const userData = { username : 'admin' }
    e.preventDefault();

    try {
      const response = await axios.post('/auth/login', {
        username,
        password,
      });

      localStorage.setItem('jwToken', response.data.token);
      alert('Login successful!');
      login(userData);
      navigate('/home');
    } catch (errorMessage) {
      setErrorMessage('Invalid credentials')
    }
    // // 간단한 로그인 체크 (role에 따라 다르게 처리)
    // if (username === 'admin' && password === '1234') {
    //   const userData = { username, role: 'admin' };
    //   login(userData);
    //   navigate('/home');
    // } else if (username === 'user' && password === '1234') {
    //   const userData = { username, role: 'user' };
    //   login(userData);
    //   navigate('/home');
    // } else {
    //   setErrorMessage('❌ 로그인 실패: 아이디 또는 비밀번호가 틀렸습니다.');
    // }
  };

  const handleSignup = () => {
    navigate('/new');
  }

  return (
    <div style={{ padding: '20px' }}>
      <h2>로그인 페이지</h2>
      <form onSubmit={handleLogin}>
        <input
          type="text"
          placeholder="아이디"
          value={username}
          onChange={(e) => setUsername(e.target.value)}
        /><br /><br />
        <input
          type="password"
          placeholder="비밀번호"
          value={password}
          onChange={(e) => setPassword(e.target.value)}
        /><br /><br />
        <button type="submit">로그인</button>
        <button type="submit" onClick={handleSignup}>회원가입</button>
      </form>

      {/* 에러 메시지 스타일링 */}
      {errorMessage && (
        <p style={{ color: 'red', marginTop: '10px' }}>{errorMessage}</p>
      )}
    </div>
  );
}

export default Login;
