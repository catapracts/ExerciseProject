// src/contexts/AuthContext.js
import { createContext, useContext, useState, useEffect } from "react";

const AuthContext = createContext();

export const AuthProvider = ({ children }) => {
  const [user, setUser] = useState(null);

  // 새로고침 시 localStorage에서 로그인 정보 가져오기
  useEffect(() => {
    const storedUser = JSON.parse(localStorage.getItem('user'));
    const storedLoginTime = localStorage.getItem('loginTime');
    const currentTime = new Date().getTime();

    // 로그인 시간과 현재 시간이 1시간 이상 차이 나면 자동 로그아웃
    if (storedUser && storedLoginTime && currentTime - storedLoginTime < 3600000) {
      setUser(storedUser);
    } else {
      localStorage.removeItem('user');
      localStorage.removeItem('loginTime');
    }
  }, []);

  const login = (userData) => {
    setUser(userData);
    localStorage.setItem('user', JSON.stringify(userData));
    localStorage.setItem('loginTime', new Date().getTime());
  };

  const logout = () => {
    setUser(null);
    localStorage.removeItem('user');
    localStorage.removeItem('loginTime');
  };

  return (
    <AuthContext.Provider value={{ user, login, logout }}>
      {children}
    </AuthContext.Provider>
  );
};

export const useAuth = () => useContext(AuthContext);
