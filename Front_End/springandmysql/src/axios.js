import axios from 'axios';

// 기본 URL 설정
const instance = axios.create({
  baseURL: 'http://localhost:8080',  // Spring Boot 서버 주소 (API 서버)
  headers: {
    'Content-Type': 'application/json',
  },
});

// JWT 토큰을 Authorization 헤더에 자동으로 추가하는 기능
instance.interceptors.request.use(
  (config) => {
    const token = localStorage.getItem('jwtToken');  // 로컬스토리지에서 토큰 가져오기
    if (token) {
      config.headers['Authorization'] = `Bearer ${token}`;
    }
    return config;
  },
  (error) => {
    return Promise.reject(error);
  }
);

export default instance;