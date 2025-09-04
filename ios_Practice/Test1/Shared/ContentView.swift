//
//  ContentView.swift
//  Shared
//
//  Created by MacBook on 2025/08/31.
//

import SwiftUI

struct ContentView: View {
    
    @State private var count = 0 // 상태변수 : 버튼 클릭시마다 값 변경됨
    @State private var userInput: String = ""  // 사용자 입력을 저장할 변수
    
    var body: some View {
        // VStack = Vertical Stack, 수직으로 뷰를 배치하는 레이아웃 컨테이너, 위에서 아래, 기본적으로 요소들 사이에 일정한 간격이 적용, spacing : 간격 조정, alignment : 정렬 방식 설정(.leading, .center, .trailing, etc), HStack과 중첩 및 함께 사용 가능
        VStack(spacing: 20) {
            Text("현재 숫자:")
                .font(.title)
                .padding(.top, 30)
            
            Text("\(count)")
                .font(.system(size: 50, weight: .bold))
                .foregroundColor(.blue)
            
            // HStack = Horizontal Stack, 수평으로 뷰를 배치하는 레이아웃 컨테이너, 좌에서 우, spacing, alignment(.top, .bottom, .center, etc), VStack과 중첩 및 함께 사용 가능
            HStack(spacing: 20) {
                Button(action: {
                    count += 1
                }) {
                    Text("+ 증가")
                        .padding(.horizontal, 20)
                        .background(Color.green)
                        .foregroundColor(.white)
                        .cornerRadius(10)
                }
                .padding([.top, .leading, .bottom], 30)
                
                Button(action: {
                    count = 0
                }) {
                    Text("초기화")
                        .padding(.horizontal, 20)
                        .background(Color.red)
                        .foregroundColor(.white)
                        .cornerRadius(10)
                }
                .padding([.top, .bottom, .trailing], 30)
            }
            
            VStack(spacing: 20) {
                Text("입력해보세요:")
                    .font(.title)
                            
                TextField("여기에 입력하세요", text: $userInput)  // 텍스트 입력창
                    .padding()
                    .textFieldStyle(RoundedBorderTextFieldStyle())
                    .frame(width: 300)
                            
                    Button(action: {
                                // 버튼을 눌렀을 때 입력값을 출력
                            print("사용자가 입력한 값: \(userInput)")
                            }) {
                                Text("입력 확인")
                                    .background(Color.green)
                                    .foregroundColor(.white)
                                    .cornerRadius(10)
                            }
                            
                            Text("입력한 값: \(userInput)")  // 입력한 값을 화면에 출력
                                .font(.headline)
                                .foregroundColor(.blue)
            }
            .padding(.bottom, 30)
        }
        /*
         이미지 파일 업로드, 다운로드
         서버통신
         데이터베이스 연동
         macos, ios 동작 확인
         */
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
            .frame(width: 800, height: 800) // 화면 크기 조정
            .previewLayout(.sizeThatFits) // 자동 크기 조정
    }
}
