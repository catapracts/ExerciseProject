//
//  ContentView.swift
//  Shared
//
//  Created by MacBook on 2025/08/19.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        NavigationView { // 화면전환을 위한 기본 구조
            VStack(spacing: 20) { // 수직정렬
                Image(systemName: "star.fill") // 이미지
                    .resizable()
                    .frame(width: 100, height: 100)
                    .foregroundColor(.yellow)
                Text("첫 번째 화면")
                    .font(.title)
                // 화면 전환
                NavigationLink(destination: SecondView()) { // 다른 view로 이동하는 역할
                    Text("다음 화면으로 이동")
                        .font(.headline)
                        .padding()
                        .background(Color.blue)
                        .foregroundColor(.white)
                        .cornerRadius(10)
                }
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
