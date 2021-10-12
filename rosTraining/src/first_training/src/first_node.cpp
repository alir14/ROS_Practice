#include <rclcpp/rclcpp.hpp>
#include <rclcpp_components/register_node_macro.hpp>

namespace first_training
{
    class FirstNode : public rclcpp::Node
    {
    public:
        explicit FirstNode(const rclcpp::NodeOptions& options) : rclcpp::Node("first_node", options)
            {
                RCLCPP_INFO(get_logger(), "my node is ready!");
            }
    private:

    };

}

RCLCPP_COMPONENTS_REGISTER_NODE(first_training::FirstNode)

