// src/components/MainPage.jsx
import { useNavigate } from 'react-router-dom';
import { useAuth } from '../contexts/AuthContext';

function Home() {
  const navigate = useNavigate();
  const { user, logout} = useAuth();

  const handleLogout = () => {
    localStorage.removeItem('isLoggedIn');
    logout();
    navigate('/');
  };

  if (!user) {
    return <p>로그인 후 이용 가능합니다.</p>;
  }

  return (
    <div>
      <h2>메인 페이지</h2>
      <h2>안녕하세요, {user?.username}님!</h2>
      <p>로그인에 성공했습니다! 🎉</p>
            {user.role === 'admin' ? (
        <div>
          <h3>관리자 페이지</h3>
          <p>여기서는 관리자만 이용할 수 있는 기능이 있습니다.</p>
        </div>
      ) : (
        <div>
          <h3>일반 사용자 페이지</h3>
          <p>여기서는 일반 사용자만 이용할 수 있는 기능이 있습니다.</p>
        </div>
      )}
      <button onClick={handleLogout}>로그아웃</button>
    </div>
  );
}

export default Home;
