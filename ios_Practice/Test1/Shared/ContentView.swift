//
//  ContentView.swift
//  Shared
//
//  Created by MacBook on 2025/08/31.
//

import SwiftUI

struct ContentView: View {
    
    @State private var count = 0 // 상태변수 : 버튼 클릭시마다 값 변경됨
    
    var body: some View {
        VStack(spacing: 20) {
            Text("현재 숫자:")
                .font(.title)
                .padding(.top, 30)
            
            Text("\(count)")
                .font(.system(size: 50, weight: .bold))
                .foregroundColor(.blue)
            
            
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
            
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
            .frame(width: 400, height: 400) // 화면 크기 조정
            .previewLayout(.sizeThatFits) // 자동 크기 조정
    }
}
