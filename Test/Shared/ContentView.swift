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

/*
 MTLIOAccelDevice bad MetalPluginClassName property (null) 오류 대처방법
 1. 맥북 리부트 후 option, command, R, P 단축키 사용 -> GPU 관련 캐시 삭제 -> 실패
 2. ~/Library/Developer/Xcode/DerivedData 해당 경로의 DerivedData를 아얘 지우기 -> Xcode에서 사용하는 모든 파생 데이터 삭제 -> 실패
 3. Shift + Command + K 단축키 사용 -> 프로젝트의 빌드 캐시를 삭제하고 Derived Data를 간접적으로 정리 -> 실패
 4. xcode 삭제 후 재설치 -> 실패
*/
