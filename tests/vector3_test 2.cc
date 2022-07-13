#include "gtest/gtest.h"
#include "vector3.h"
#include <string>


class Vector3Test : public ::testing::Test {
public:
  void SetUp( ) { 
    pi_vector = Vector3(3.1415, 1.4159, 4.159);
    nil_vector = Vector3(0,0,0);
    big_vector = Vector3(324506.01439, 245630.356, 100042.20);

  }
protected:
    Vector3 pi_vector;
    Vector3 nil_vector;
    Vector3 big_vector;
};

TEST_F(Vector3Test, VectorPrintTest) {  

    std::string expected_out_1 = "[3.1415, 1.4159, 4.159]\n";  
    std::string expected_out_2 = "[0, 0, 0]\n";  
    std::string expected_out_3 = "[324506.01439, 245630.356, 100042.20]\n"; 

    testing::internal::CaptureStdout();
    pi_vector.Print();
    std::string output_1 = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    nil_vector.Print();
    std::string output_2 = testing::internal::GetCapturedStdout();
    
    testing::internal::CaptureStdout();
    big_vector.Print();
    std::string output_3 = testing::internal::GetCapturedStdout();
    
    EXPECT_EQ(output_1, expected_out_1);
    EXPECT_EQ(output_2, expected_out_2);
    EXPECT_EQ(output_3, expected_out_3);

}


TEST_F(Vector3Test, OperatorsTest){

    Vector3 sum_test(10.5, 24.3, 18.49);
    Vector3 uniform_vector1(1.0, 1.0, 1.0);
    Vector3 uniform_vector2(2.0, 2.0, 2.0);
    Vector3 uniform_vector3(3.0, 3.0, 3.0);

    double two = 2.0;
    Vector3 result_vector;

    std::string expected_output_1 = "[10.5, 24.3, 18.49]\n";
    std::string expected_output_2 = "[9.5, 23.3, 17.49]\n";
    std::string expected_output_3 = "[6.0, 6.0, 6.0]\n";
    std::string expected_output_4 = "[1.5, 1.5, 1.5]\n";

    
    testing::internal::CaptureStdout();
    result_vector = nil_vector + sum_test;
    result_vector.Print();
    std::string output_1 = testing::internal::GetCapturedStdout(); 

    testing::internal::CaptureStdout();
    result_vector = sum_test - uniform_vector1;
    result_vector.Print();
    std::string output_2 = testing::internal::GetCapturedStdout(); 

    testing::internal::CaptureStdout();
    result_vector = uniform_vector3 * two;
    result_vector.Print();
    std::string output_3 = testing::internal::GetCapturedStdout(); 

    testing::internal::CaptureStdout();
    result_vector = uniform_vector3 / two;
    result_vector.Print();
    std::string output_4 = testing::internal::GetCapturedStdout(); 



    EXPECT_EQ(output_1, expected_output_1);
    EXPECT_EQ(output_2, expected_output_2);
    EXPECT_EQ(output_3, expected_output_3);
    EXPECT_EQ(output_4, expected_output_4);
}

TEST_F(Vector3Test, GetXTest){
    EXPECT_EQ(pi_vector.getX(), 3.1415);
    EXPECT_EQ(nil_vector.getX(), 0);
    EXPECT_EQ(big_vector.getX(), 324506.01439);
}

TEST_F(Vector3Test, GetYTest){
    EXPECT_EQ(pi_vector.getY(), 1.4159);
    EXPECT_EQ(nil_vector.getY(), 0);
    EXPECT_EQ(big_vector.getY(), 245630.356);
}

TEST_F(Vector3Test, GetZTest){
    EXPECT_EQ(pi_vector.getZ(), 4.159);
    EXPECT_EQ(nil_vector.getZ(), 0);
    EXPECT_EQ(big_vector.getZ(), 100042.20);
}


TEST_F(Vector3Test, SetXYZTest){
    Vector3 vec123(1.0, 2.0, 3.0);
    Vector3 vec323(3.0, 2.0, 3.0);
    Vector3 vec173(1.0, 7.0, 3.0);
    Vector3 vec129(1.0, 2.0, 9.0);
    Vector3 result_vector;

    EXPECT_EQ(vec123.setX(3.0), vec323);
    EXPECT_EQ(vec123.setY(7.0), vec173);
    EXPECT_EQ(vec123.setZ(9.0), vec129);
}


TEST_F(Vector3Test, NormalizeTest){
    double test_magnitude = sqrt(1.0 + 4.0 + 9.0);
    Vector3 normalizedVector(1.0/test_magnitude, 2.0/test_magnitude, 3.0/test_magnitude);
    Vector3 vec123(1.0, 2.0, 3.0);

    EXPECT_EQ(vec123.Normalize(), normalizedVector);
    EXPECT_EQ(nil_vector.Normalize(), nil_vector);
}
